#include<bits/stdc++.h>
using namespace std;

int N, T, D, a[1111], t[1111], dp[1111][111];


int main(){
  cin >> N >> T >> D;
  for( int i = 1; i <= N; i++){
    cin >> a[i];
  }
  for( int i = 1; i <= N; i++){
    cin >> t[i];
  }
  t[0] = 0;
  int ans = 0;
  for( int i = N; i > N - D ; i--){
    int temp = 0;
    for( int j = i - 1; j >= max(1,i - D) ; j-- ){
      if( T >= t[j]){
       dp[j][T-t[j]] = dp[i][T] + a[j];
      }
    }
  }
  cout << ans;
  return 0;
}
