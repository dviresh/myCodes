#include<iostream>
#include<string>

using namespace std; 

struct Node{
	int data;
	int count;
	
	struct Node *left;
	struct Node *right;
	struct Node *prev;
}

void createNode(){
	struct Node *leaf = new struc
}

void bst(int element, int index){
	if(index == 0){
		cout<<"first node"<<endl;
		createNode(element);
	}
	
}
int main(){
	
	cout<<"enter the elements of the tree"<<endl;
	
	string s, out; 
	int x; 
	stringstream ss; 
	int *arr = new int(sizeof(int));
	getline(cin,s);
	ss<<s;
	
	int i=0,;
	while(ss>>out){
		stringstream convert(out); 
		convert>>x; 
		arr[i]=x;
		i++;
	}
	int arrlen=i;
	
	for(int i=0; i<arrlen; i++){
		bst(arr[i],i);
	}

	
	return 0;
}