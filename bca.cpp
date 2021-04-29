#include<bits/stdc++.h>
using namespace std;
#define M 11 
#define N 33

int m,n,minl=999999,maxload=0,load[M],flag=0;
set<int> T[N];
int C[N][N],B[M][N],X[N];

bool check(int i, int k){
  for( int v=1; v<=k-1; v++){
    if( C[v][k]==1 ){
      if( X[v]==i ) return false;
    }
  }
  return true;
}

void TRY( int k){
  for( set<int>::iterator i=T[k].begin(); i!=T[k].end(); i++){
    if(check(*i,k)){
      X[k]=*i;
      load[*i]++;
      int remem=maxload;
      maxload =max(maxload,load[*i]);
      if(k==n){
        minl=min(minl,maxload);
      }
      else if( maxload<minl){
        TRY(k+1);
      }
      load[*i]--;
      maxload=remem;
    }
  }
}

int main(){
  cin >> m >> n;
  for( int i=1; i<=m; i++){
    int cnt;
    cin >> cnt;
    while(cnt--){
      int sj;
      cin >> sj;
      T[sj].insert(i);
    }
  }
  int k;
  cin >> k;
  for( int i=0; i<=n; i++){
    for( int j=0; j<=n; j++){
      C[i][j]=0;
    }
  }
  for( int i=1; i<=k; i++){
    int sj1, sj2;
    cin >> sj1 >> sj2;
    C[sj1][sj2]=1;
    C[sj2][sj1]=1;
  }
  
  for(int i=1; i<=n; i++) X[i]=0;
  TRY(1);
  if( minl==999999) cout << -1;
  else cout << minl;
  return 0;
}