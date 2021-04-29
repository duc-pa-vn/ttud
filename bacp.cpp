#include<bits/stdc++.h>
using namespace std;
#define N 22
#define M 10

int n,m,c[N],A[N][N],X[N],load[M],minimal=999999,maxload=0;

bool check( int i, int k){
  for( int v=1; v<=n; v++){
    if( A[v][k]==1){
      if( X[v]>=i) return false;
    }
    if( A[k][v]==1){
      if( X[v]<=i && X[v]!=0) return false;
    }
  }
  return true;
}

void TRY(int k){
  for( int i=1; i<=m; i++){
    if( check(i,k) ){
      X[k]=i;
      load[i]+=c[k];
      int remem=maxload;
      maxload=max(maxload,load[i]);
      if(k==n){
        minimal=min(minimal,maxload);
      }else if(maxload<minimal){
        TRY(k+1);
      }
      maxload=remem;
      load[i]-=c[k];
      X[k]=0;
    }
  }
}

int main(){
  cin >> n >> m;
  for( int i=1; i<=n; i++){
    cin >> c[i];
  }
  for( int i=1; i<=n; i++){
    for( int j=1; j<=n; j++){
      cin >> A[i][j];
    }
  }
  for( int i=0; i<=n; i++) X[i]=0;
  for( int i=0; i<=m; i++) load[i]=0;
  TRY (1);
  cout << minimal;
  return 0;
}