data<-read.csv("DoorFreq_10min_03302016.csv")
################################################
x<-as.character(data$Datetime)
data$Var1<-as.POSIXct(x,format="%Y-%m-%d %H:%M:%S",tz="")
x1<-format(data$Var1,"%H:%M")
x2<-sub("\\:","",x1)
data$h_m<-as.numeric(x2)
y1<-format(data$Var1,"%d")
data$day<-as.numeric(y1)
y2<-format(data$Var1,"%m")
data$month<-as.numeric(y2)
y3<-format(data$Var1,"%Y")
data$year<-as.numeric(y3)
z1<-strftime(data$Var1,"%B")
data$months<-z1
write.csv(data,"new_data.csv")
f_data<-subset(f_data,h_m>450)
f_data$h_m