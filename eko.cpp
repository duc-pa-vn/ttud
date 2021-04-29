#include<bits/stdc++.h>
using namespace std;

int N, high[9999999], H;
long long W, M;

long long cut(int mid){
  W = 0;
  for( int i=1; i<=N; i++){
    if( mid<high[i]) W += high[i] - mid;
  }
  return W;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> N >> M;
  for( int i=1; i<=N; i++){
    cin >> high[i];
  }
  int l = 0, r = 999999999, mid;
  mid = (l + r)/2;
  while( mid != l){
    if( cut(mid) > M ) l = mid;
    else if( cut(mid) == M) break;
    else r = mid;
    mid = (l + r)/2;
  }
  cout << mid;
  return 0;
}

