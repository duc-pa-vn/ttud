#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int n, K, Q, d[100];
int Y[MAX], X[MAX], load[MAX], visitted[MAX], dis[MAX][MAX], mindis=999999;
int segment=0, distances=0,mind=999999,lower=0;
bool checkX( int v, int i, int k){
  if( visitted[v]==1 && v>0) return false;
  if( load[k]+d[v]>Q ) return false;
  if( v==0 && k==K){
    if( (segment+1) < (n+K)) return false;
  }
  return true;
}

void TRY_X(int i,int k){
  for( int v=0; v<=n; v++){
    if( checkX(v,i,k)){
      X[i]=v;
      load[k]+=d[v];
      visitted[v]=1;
      segment++;
      distances+=dis[i][v];
      if( v==0){
        if( k==K){
           if( segment==(n+K)) mindis=min(mindis,distances);
        }
        else{
          if(distances < mindis) TRY_X(Y[k+1],k+1);
        }
      }
      else{
        if(distances < mindis)
        TRY_X( v,k);
      }
      load[k]-=d[v];
      visitted[v]=0;
      segment--;
      distances-=dis[i][v];
    }
  }
}

bool checkY( int v, int k){
  if( visitted[v]==1  && v>0) return false;
  if( (load[k]+d[v])>Q ) return false;
  return true;
}

void TRY_Y( int k){
  for( int v=Y[k-1]+1; v<=n; v++){
    if( checkY(v, k)){
      Y[k]=v;
      load[k]+=d[v];
      segment++;
      visitted[v]=1;
      distances+=dis[0][v];
      if( k==K){
        lower=distances+(n+K-k)*mind;
        if(lower < mindis) TRY_X(Y[1],1);
      }
      else{
        lower=distances+(n+K-k)*mind;
        if(lower < mindis) TRY_Y(k+1);
      }
      load[k]-=d[v];
      segment--;
      visitted[v]=0;
      distances-=dis[0][v];
    }
  }
}

int main(){
  cin >> n >> K >> Q;
  for ( int i=1; i<=n; i++){
    cin >> d[i];
  }
  for( int i=0; i<=n; i++){
    for( int j=0; j<=n; j++){
      cin >> dis[i][j];
    }
  }
  for( int i=0; i<=n; i++){
    for( int j=0; j<=n; j++){
      if( i==j ) continue;
      else mind=min(mind,dis[i][j]);
    }
  }
  X[0]=0;Y[0]=0;d[0]=0;
  for( int i=1; i<=K; i++) load[i]=0;
  for( int i=0; i<=n; i++) visitted[i]=0;
  TRY_Y(1);
  cout << mindis;
  return 0;
}