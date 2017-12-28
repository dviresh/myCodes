#include<iostream>

using namespace std;


int *
coupled (int arr[], int n)
{

  int ret_arr[n];

  for (int i = 0; i < n; i++)
    {
      ret_arr[i] = 0;
    }

  int *start, *end, *pivot1, *pivot2, *pivot3;
  start = &arr[0];
  end = &arr[n - 1];
  pivot1 = start;
  pivot2 = &arr[1];
  pivot3 = &ret_arr[0];

  for (int i = 0; i < n; i++)
    {
      while (*pivot1 != *pivot2 &&  pivot2 != end && pivot1 != end)
	{
//	  cout<<"hey"<<"\n";
	  pivot2++;
	if(pivot1 == pivot2){
        pivot2++;
        }

	}
      if (pivot2 == end && *pivot2 != *pivot1)
	{
//	  cout<<"loop1"<<"\n";
	  *pivot3 = *pivot1;
	  cout<<*pivot1;
	  pivot1++;
	  pivot3++;
	  pivot2 = start;
	}
      else
	{
//	  cout<<"loop2"<<"\n";
	  pivot1++;
	  pivot2 = start;
	}

    }

  pivot3 = &ret_arr[0];
/*
  while (*pivot3 != 0)
    {
      cout << *pivot3;
    }
*/
}



int
main ()
{

  int n;
  cout << "enter the no. of numbers" << "\n";
  cin >> n;

  int arr[n];

  cout << "enter the elements except 0 " << "\n";

  for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

  coupled (arr, n);

  return 0;
}
