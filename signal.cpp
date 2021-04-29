#include<bits/stdc++.h>
using namespace std;
#define MAX 200010
int a[MAX],maxleft[MAX],maxright[MAX];

int main(){
  int n,b,re=-1;
  cin >> n >> b;
  for( int i=1; i<=n; i++) cin  >> a[i];
  maxleft[1]  =a[1];
  for(int i=2  ; i<=n; i++) maxleft[i]=max(maxleft[i-1],a[i]);
  maxright[n] =a[n];
  for(int i=n-1; i>=1; i--) maxright[i]=max(maxright[i+1],a[i]);
  for( int i=2; i<n; i++){ 
    int left  =maxleft[i]-a[i];
    int right =maxright[i]-a[i];
    if( left>=b && right>=b) re=max(left+right,re);
  }
  cout << re;
}
