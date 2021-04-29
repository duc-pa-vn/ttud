#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n, m, dp[555][101], sm[101];

int countways(int currt, int i){
  if(i == 0){
    if( currt == 0) return 1;
    else return 0;
  }
  if( dp[currt][i] != -1) return dp[currt][i];
  int ways = 0;

  for( int j = 1; j <= currt/sm[i]; j++){
    ways += countways(currt-j*sm[i],i-1);
  }
  cout <<  currt << " " << i << " " << ways << endl;
  ways = ways % MOD;
  return dp[currt][i] = ways;
}

int main(){
  cin >> n >> m;
  for( int i = 1; i <= n; i++) cin >> sm[i];
  memset(dp,-1,sizeof(dp));
  cout << countways(m,n);
  return 0;
}