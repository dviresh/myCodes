#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

void getRange(int n , int m){

	int numbers[m-n];
	int j=0;
	for(int i=n; i<m; i++){
		if(i%2 != 0){
			numbers[j]=i;
			cout<<numbers[j]<<endl;
			j++;
		}
	}

}

int main(){
	int n,m;
	cout<<"enter the 1st number"<<endl;
	cin>>n;
	cout<<"enter the second number"<<endl;
	cin>>m;

	getRange(n,m);



return 0; 
}

