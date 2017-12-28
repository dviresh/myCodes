#include<iostream>

using namespace std;

int
fib (int n)
{

  int arr[n];

  arr[0] = 0, arr[1] = 1;

  for (int i = 2; i < n+1; i++)
    {
      arr[i] = arr[i - 1] + arr[i - 2];
     // cout<<arr[i]<<"\n";
    }

  return (arr[n]);
}


int
main ()
{

  int n;
  cout << "enter the number of series" << "\n";
  cin >> n;

  int arr[n];
  cout << "enter the numbers" << "\n";
  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

  for (int i = 0; i < n; i++)
    {
      int number = arr[i];
      int result = fib (number);
      cout << result << "\n";
    }

  return 0;
}
