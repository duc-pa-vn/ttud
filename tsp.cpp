#include<bits/stdc++.h>
using namespace std;

#define IFN 10000000
int n,m,c,cmin=10000000;
int costmap[21][21];
int visitted[21];
int path[33];
long mincost=1000000*22,cost=0,lower;

bool check(int i){
  return visitted[i]==0 ;
}

void TRY(int k){
 for( int i=2; i<=n; i++){
    if(check(i)){
      path[k]=i;
      visitted[i]=1;
      cost+=costmap[path[k-1]][i];
      if(k==n){
       if(mincost > (cost+costmap[path[k]][1]) ) mincost=cost+costmap[path[k]][1];
      }else{
       lower=cost+cmin*(n-k+1);
       if(lower<mincost) TRY(k+1);
      }
      visitted[i]=0;
      cost-=costmap[path[k-1]][i];
    }
  }
}

int main(){
  cin >> n >> m;
  for( int i=1; i<=n; i++){
    for( int j=1; j<=n; j++){
      costmap[i][j]=IFN;
    }
  }
  for( int i=0; i<m; i++){
    int x,y;
    cin >> x >> y;
    int weight; 
    cin >> weight;
    if( cmin >weight ) cmin = weight;
    costmap[x][y] = weight;
  }
  for(int i=0; i<21; i++){
    visitted[i]=0;
  }
  path[1]=1;
  TRY(2);
  cout << mincost;
  return 0;
}