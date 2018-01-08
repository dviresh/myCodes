/* 

Google's interview question

This program returns the first duplicate element encountered in a array. If no duplicate element is present then it returns -1. 

*/
#include<iostream>

using namespace std;

int firstDuplicate(int arr[], int n){
	
	int duplicate = 0;
	
	int *start, *end, *pivot;
	int *bstart, *bend, *bpivot1, *bpivot2;
	
	start = &arr[0];
	end   = &arr[n-1];
	pivot = start;
	
	int *barr = new int(sizeof(int));
	int i = 0;
	barr[i] = 0;
	int j = i+1;
	bstart = &barr[0];
	bend = &barr[j];
	bpivot1 = bstart; 
	bpivot2 = bstart;
	*bend = 0;
	
	while(pivot != end++){
		
		while(bpivot1 != bend){
			
			if(*bpivot1 != *pivot){
				if(bpivot1 == bpivot2){
					*bpivot1 = *pivot;
					bpivot1++;
					bpivot2++;
				}
				else{
					bpivot1++;
				}
			}
			else if(*bpivot1 == *pivot){
				
				
				duplicate = *pivot;
				goto label1;
				
			}
		}
		
		bend = &barr[j++];
		pivot++;
		bpivot1 = bstart;
		
	}
	
	
	if(duplicate == 0){
		duplicate = -1;
	}

	label1 : return duplicate;
	
}

int main(){
	
	cout<<"enter the no. of elements"<<endl;
	int n;
	cin>>n; 
	int arr[n];
	cout<<"enter the elements excpet 0"<<endl;
	for(int i=0; i<n; i++){
	cin>>arr[i];
	}
	int duplicate = firstDuplicate(arr,n);
	if(duplicate == 0){
		cout<<"the first duplicate element is "<<-1<<endl;
	}
	else{
	cout<<"the first duplicate element is "<<duplicate<<endl;
	}
	return 0;
}