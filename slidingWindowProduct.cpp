#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int slidingWindowProduct(int arr[], int n, int maxproduct){
	int i=0, winsize=0,count, product = 1, productCount=0;
	int *start, *end, *ps, *pe, *p;
	int arrlen = n;
	while(n != 0){
		winsize = n;
		count=(arrlen+1)-winsize;
		
		start=&arr[0];
		end  =&arr[arrlen-1];
		ps = &arr[0];
		pe = &arr[winsize-1];
		p=ps;
		
		while(count != 0){
			while(p != pe){
				product *= (*p);
				p++;
			}
			product *= (*p);
			p=ps;
			
			if(pe != end){
				ps++;
				pe++;
			}
			p=ps;
			count--;
			if(product <= maxproduct){
				productCount++;
			}
			product = 1;
		}
		n--;
	}
	return productCount;
}

int main(){
	string s, out;
	stringstream ss;
	int x, i=0, arrlen=0;
	int *arr = new int(sizeof(int));
	cout<<"enter the elements of the array"<<endl;
	getline(cin,s);
	ss<<s;
	while(ss>>out){
		stringstream convert(out);
		convert>>x;
		arr[i]=x;
		i++;
		arrlen++;
	}
	int product;
	cout<<" enter the maximum product"<<endl;
	cin>>product;
	int count = slidingWindowProduct(arr, arrlen, product);
	cout<<"no. of sub arrays whose product is less than"<<"\t"<<product<<"\t"<<"is"<<"\t"<<count<<endl;

	return 0;
}