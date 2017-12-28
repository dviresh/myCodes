#include <iostream>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int n;
    cout<<"enter the number of iterations"<<"\n";
    cin>>n;
    
    int f,i_prev=0, i=1;
    while(n!=0){
        f = i_prev+i;
	i_prev = i;
        i++;
        n--;
	cout<<f<<"\n";
    }
    //cout<<"fibnocci number is"<<f;
    return 0;
}

