#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std ;
#define MAXN 100002
#define MAX 1000002
int n,a[MAXN],c[MAX] ;
int main()
{
 int runs ;
 scanf("%d",&runs) ;
 while(runs--)
 {
  scanf("%d",&n) ;
  for(int i = 0;i < n;i++) scanf("%d",&a[i]) ;
  long long ret = 1LL * n * (n - 1) / 2 ;
  memset(c,0,sizeof c) ;
  for(int i = 0;i < n;i++)
  {
   for(int j = a[i];j > 0;j -= j & -j) ret -= c[j] ;
   for(int j = a[i];j < MAX;j += j & -j) c[j]++ ;
  }
  cout << ret << endl ;
 }
 return 0 ;
}