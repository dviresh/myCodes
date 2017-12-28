library(shiny)
library(shinydashboard)
library(ggplot2)
library(xts)
library(dygraphs)
f_data<-read.csv("new_data.csv")
x<-as.character(f_data$Var1)
f_data$Var1<-as.POSIXct(x,format="%Y-%m-%d %H:%M:%S",tz="")
x1<-format(f_data$Var1,"%H:%M")
x2<-sub("\\:","",x1)
f_data$h_m<-as.numeric(x2)
f_data<-subset(f_data,h_m>450)


sidebar<- dashboardSidebar(
  hr(),
  sidebarMenu(id="tabs",
    menuItem((strong("CHARTS")),icon = icon("line-plot"),tabName = "chart",selected = TRUE),
  
  menuItem(strong(("HISTORIC PLOTS")), tabName = "hplot",
           menuSubItem(strong("Busiest Year"),tabName = "y",icon = icon("angle-right")),
           menuSubItem(strong("Busiest Month"),tabName = "m",icon = icon("angle-right")),
           menuSubItem(strong("Busiest Day"),tabName = "d",icon = icon("angle-right")))
),

hr(),
conditionalPanel("input.tabs=='chart'",
                 fluidRow(
                   selectInput("day",
                               label=h4(strong(("Day"))),
                               choices = c(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30),
                               selected = "1"
                   ),
                   selectInput("month",
                               label=h4(strong(("Month"))),
                               choices = c("January","February","March","April","May","June","July","August","September","October","November","December"),
                               selected = "October"
                   ),
                   selectInput("year",
                               label=h4(strong("Year")),
                               choices = c(2012,2013,2014,2015),
                               selected = 2013
                   )  
                 )
                 )
)
body<-dashboardBody(
  fluidRow(
    #valueBoxOutput("text1"),
    box(width=12,height=90,h2(strong(textOutput("text"))),solidHeader = TRUE,align="center"),
    valueBoxOutput("total"),
    valueBoxOutput("mean"),
    valueBoxOutput("status")
    
  ),
  tabItems(
    tabItem(tabName = "chart",
                   fluidRow(
                     box(width = 12,height = 500,collapsible=TRUE,dygraphOutput("dygraph"),
                    sliderInput("range","Time:",min = 530,max = 2300,value = c(530,2300))   
                   )
            )
    ),
    tabItem(tabName = "y",
            fluidRow(
              box(width = 12, height = 500,collapsible = TRUE,plotOutput("y"))
            )
            ),
    tabItem(tabName = "m",
            fluidRow(
              box(width = 12, height = 500,collapsible = TRUE,plotOutput("m"))
            )
    ),
    tabItem(tabName = "d",
            fluidRow(
              box(width = 12, height = 500,collapsible = TRUE,plotOutput("d"))
            )
    ) 
    ),
fluidRow(
  column(width = 10,
         tabBox(
           title = "Notifications",
           # The id lets us use input$tabset1 on the server to find the current tab
           id = "tabset1", height = "250px",
           tabPanel("No new notifications")
                    ),
          tabBox(
           title = "Events",
           # The id lets us use input$tabset1 on the server to find the current tab
           id = "tabset1", height = "250px",
           tabPanel("No new events")
       )  
  )
  
)

)
ui<-dashboardPage(
  dashboardHeader(title = h4(strong("Data Mining Agent"))
                  ),
  sidebar,
  body
)





server <- function(input,output,session){
 output$text<-renderText({paste("CROWD ON:",input$month,"-",input$day,"-",input$year)})
  observe({
    d<-input$day
    m<-input$month
    y<-input$year
    s_data<-subset(f_data,day==d&months==m&year==y)
    if(s_data$DoW=="Saturday"){
      updateSliderInput(session,"range","Time:",min = 900, max = 2330, value = c(900,2330))  
    }
    else if(s_data$DoW=="Sunday"){
      updateSliderInput(session,"range","Time:",min = 900, max = 2330, value = c(900,2330))
    }
   else{
     updateSliderInput(session,"range","Time:",min = 530, max = 2330, value = c(530,2330))
   
   }
  })
  output$total <- renderValueBox({
    s_data<-subset(f_data,day==input$day& months== input$month & year==input$year&h_m>input$range[1]&h_m<input$range[2])
    valueBox(
      format(sum(s_data$Freq),format="d",big.mark=","), strong("Total Number of Students"), icon = icon("area-chart"), color = "blue")
  })
  output$mean <- renderValueBox({
    s_data<-subset(f_data,day==input$day& months== input$month & year==input$year&h_m>input$range[1]&h_m<input$range[2])
    valueBox(
      format(round(mean(s_data$Freq)),format="d",big.mark=","), strong("Average number of students"), icon = icon("area-chart"), color = "red")
  })
  output$status<- renderValueBox({
    s_data<-subset(f_data,day==input$day& months== input$month & year==input$year&h_m>input$range[1]&h_m<input$range[2])
    if(sum(s_data$Freq)>1000&sum(s_data$Freq)<1500){
      valueBox(
        format("Perfect",format="d",big.mark=","), strong("Status of SRC"), icon = icon("area-chart"), color = "green")
    }
    else if(sum(s_data$Freq)>1500){
      valueBox(
        format("Busy",format="d",big.mark=","), strong("Status of SRC"), icon = icon("area-chart"), color = "green")  
    }
    else {
      valueBox(
        format("Free",format="d",big.mark=","), strong("Status of SRC"), icon = icon("area-chart"), color = "green")
      
    }
    
  })
  
  output$y<-renderPlot({ggplot(f_data,aes(year,Freq,colour=year))+geom_bar(stat="identity")})
  output$m<-renderPlot({ggplot(f_data,aes(months,Freq,colour=months))+geom_bar(stat="identity")})
  output$d<-renderPlot({ggplot(f_data,aes(DoW,Freq,colour=DoW))+geom_bar(stat="identity")})
  output$dygraph<-renderDygraph({
    
    s_data<-subset(f_data,day==input$day& months== input$month & year==input$year&h_m>input$range[1]&h_m<input$range[2])
    x_data<- xts(x = s_data$Freq, order.by = s_data$Var1)
    dygraph(x_data)
    
    
  })
  
  
  
  ###################################################
  logfilename <- paste0('logfile$value','.csv')
  obs <- observe({    
    cat(input$day,Sys.Date(), '\n', file = logfilename, append = TRUE)
  })
  
  
  
  
  # When the client ends the session, suspend the observer.
  # Otherwise, the observer could keep running after the client
  # ends the session.
  session$onSessionEnded(function() {
    obs$suspend()
    
    # Also clean up the log file for this example
    
  })
  
}
shinyApp(ui,server)
