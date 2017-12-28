#include<stdio.h>
 
int fib(int n)
{
  /* Declare an array to store Fibonacci numbers. */
  int f[n+1];
  int i;
 
  /* 0th and 1st number of the series are 0 and 1*/
  f[0] = 0;
  f[1] = 1;
 
  for (i = 2; i <= n; i++)
  {
      /* Add the previous 2 numbers in the series
         and store it */
      f[i] = f[i-1] + f[i-2];
      printf("%d\n",f[i]);
  }
 
  return f[n];
}
 
int main ()
{
  int n = 9;
   fib(n);
  getchar();
  return 0;
}
