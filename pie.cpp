#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
int N, F, test, sum;
double r[99999], s[99999];

int main(){
  scanf("%d",&test);
  while(test--){
    scanf("%d%d",&N,&F);
    F++;
    for( int i = 1 ; i <= N ; i++){
        scanf("%lf",&r[i]);
        s[i] = pi*r[i]*r[i];
    }
    double l = 0.0, r = 1000000000.0, mid;
    int k = 100;
    while(k--){
      sum = 0;
      mid = (l + r)/2.0;
      for( int i = 1 ; i <= N ; i++){
        sum += (int)(s[i]/mid);
      }
      if( sum < F) r = mid;
      else{ 
        l = mid;
      }  
    } 
    printf("%.6lf\n",mid);

  }
  return 0;
}

