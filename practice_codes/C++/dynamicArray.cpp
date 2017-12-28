#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std; 



int main(){
	string s, out; int i=0;
	stringstream ss;

	int x;
	getline(cin, s);
	ss<<s;
	// declaring dynamic array
	int *array = new int(sizeof(int));
	cout<<"enter the numbers with spaces"<<endl;
       while(ss>>out){	
		stringstream convert(out);
		convert>>x;
		array[i]=x;
		cout<<array[i]<<endl;
		i++;
	}

	}	return 0;


/* 	---- Code for sting with comma	

int main()
{

	std::string input = "abc,def,ghi";
	std::istringstream ss(input);
	std::string token;

	while(std::getline(ss, token, ',')) {
		    std::cout << token << '\n';
	}

	return 0;
}
*/
