#include<bits/stdc++.h>
using namespace std;

int check(int n, int m, int a[], int b[])
{
   if(n == 0 || m == 0)
       return 0;
   if(a[n - 1] == b[m - 1]){
       return (check(n - 1, m - 1, a, b) + 1);
   }
   return (check(n - 1, m, a, b) > check(n, m - 1, a, b)? check(n - 1, m, a, b) : check(n, m - 1, a, b));
}

int main(){
   int a[4];	nhap(&a);
   int b[5]; 	nhap(&b);
   int r = check(4, 5, a, b);
   return 0;
}

