#include<bits/stdc++.h>
using namespace std;

int merge(int a[], int l, int m, int r){
  int n1=m-l+1;
  int n2=r-m;
  int *L= new int[n1];
  int *R= new int[n2];
  for(int i=0; i<n1; ++i) L[i]=a[l+i];
  for(int i=0; i<n2; ++i) R[i]=a[m+1+i];
  int i=0, j=0, k=l;
  while(i<n1 && j<n2){
    if(L[i]<R[j]) {
      a[k]=L[i];
      ++i;
    }else{
      a[k]=R[j];
      ++j;
    }
    ++k;
  }
  while(i<n1) a[k++]=L[i++];
  while(j<n2) a[k++]=R[j++];
}

int mergesort(int a[], int l, int r){
  if(l<r){
    int m= (l+r)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
  }
}

int main(){
  int n;
  cin >> n;
  int *a= new int[n];
  for( int i=0; i<n; ++i) cin >> a[i];
  mergesort(a, 0,n-1);
    for(int i=0; i<n; ++i)
      cout << a[i] << ' ';
  return 0;
}