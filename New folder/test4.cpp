#include<bits/stdc++.h>
using namespace std;
int n, h;
double cals, ans[999999], best = -1e9, cal , a[999999];
int main(){
  memset( ans, -1e9, sizeof(ans));
  scanf("%d%d",&n,&h);
  for( int i = 1; i <= n; i++){
    scanf("%lf",&a[i]);
  }
  for( int i = 1; i<= n-h+1; i++){
    cal = 0.0;
    for( int j = i; j<=n; j++){
      cal += a[j];
      if( (j-i+1)>= h){
        cals = (double)( cal/(j-i+1));
        ans[j-i+1] = (double) max( ans[j-i+1],cals);
      }
    }
  }
  for( int i = h; i <= n; i++){
    best = (double) max( best, ans[i]);
  }
  printf("%.5lf",best);
  return 0;
}

