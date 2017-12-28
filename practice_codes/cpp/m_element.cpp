#include<iostream.h>
#include<bits/stdc++.h>
using namespace std;

struct NODE
{
    long long int num;
    struct NODE *next;
}node;

int main() {
    long long int n,a=0,i=0;
    string s;
    cin>>n;
    getline(cin,s);//whitespace
    getline(cin,s);
    //head of linked list
    while(s[i]!=' '&&s[i]!='\0')
    {
        a*=10;
        a+=(s[i]-'0');
        i++;
    }
    struct NODE *head,*temp,*temp1;
    head=((NODE*)malloc(sizeof(NODE)));
    head->num=a;
    head->next=NULL;
    temp=head;
    if(s[i]!='\0')
        i++;
    //rest of the elements
    while(s[i]!='\0')
    {
        a=0;
        while(s[i]!=' '&&s[i]!='\0')
        {
            a*=10;
            a+=(s[i]-'0');
            i++;
        }
        temp1=((NODE*)malloc(sizeof(NODE)));
        temp->next=temp1;
        temp=temp->next;
        temp->num=a;
        temp->next=NULL;
        if(s[i]!='\0')
            i++;
    }
    temp=head;
    temp1=head;
    //MAIN LOGIC
    while(n--)
    {
        if(temp1==NULL)
        {
            cout<<"NIL";
            return 0;
        }
        temp1=temp1->next;
    }
    while(temp1!=NULL)
    {
        temp=temp->next;
        temp1=temp1->next;
    }
    if(temp!=NULL)
        cout<<temp->num;
    else
        cout<<"NIL";
    return 0;
}
