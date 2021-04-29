#include<bits/stdc++.h>
using namespace std;

int n;
int dis=0,mindis=9999999,lower,cmin=999999;
int dismap[30][30],path[13];
int taken[13];

bool check(int i){
  return taken[i]==0;
}

void TRY(int k){
  for( int i=1; i<=n; i++){
    if( check(i)){
      path[k]=i+n;
      taken[i]=1;
      dis+=dismap[path[k-1]][i]+dismap[i][i+n];
      if( k==n ){
        mindis=min(mindis,dis+dismap[path[k]][0]);
      }else{
        lower=cmin*(2*(n-k)+1)+dis;
        if( lower <mindis) TRY(k+1);
      }
      taken[i]=0;
      dis-=dismap[path[k-1]][path[k]-n]+dismap[path[k]-n][path[k]];
    }
  }
}

int main(){
  cin >> n;
  for( int i=0; i<=2*n; i++){
    for( int j=0; j<=2*n; j++){
      cin >> dismap[i][j];
    }
  }
  for( int i=0; i<=2*n; i++){
    for( int j=0; j<=2*n; j++){
      if(i==j) continue;
      cmin=min(cmin,dismap[i][j]);
    }
  }
  for( int i=0; i<=13; i++){
    taken[i]=0;
    path[i]=0;
  }
  TRY(1);
  cout << mindis;
  return 0;
}