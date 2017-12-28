#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void palindromeSubArray(char arr[], int n){
	
	char *newarr = new char(sizeof(char));
	int counter =0;
	int origsize=n;
	while(n!=0){
		
		int size = (origsize+1)-n;
		
		char *start,*end,*ps,*pe,*p, *nps, *npe, *np;
		
		start = &arr[0];
		end   = &arr[origsize-1];
		ps = &arr[0];
		pe = &arr[size-1];
		p=ps;
		
		nps = &newarr[0];
		np = nps;
		npe = nps;
		
		
			while(pe != end ){
				while(size != 0 ){
				if(*p != *np){
					*np = *p;
					npe++;
					np=nps;
					counter++;
					cout<<counter<<endl;
				}
				
			}
			ps++;
			pe++;
			p=ps;
			
		}
	}
	
}

int main(){
	char s, out; 
	stringstream ss;
	
    int i=0;
    char *arr = new char(sizeof(char));
    cout<<"enter the string"<<endl;
    
    //ss<<s;
    while(){
    	arr[i]=s[i];
    	i++;
    }
    int arrlen=i;
    
    palindromeSubArray(arr,arrlen);
	       
	return 0;
}

