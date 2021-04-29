#include<bits/stdc++.h>
using namespace std;

int n,h;
int dis=0,mindis=9999999,lower,cmin=999999,cur=0;
int dismap[30][30],path[30];
int taken[13],drop[30];

bool check1(int i){
  return taken[i]==0 && cur<h;
}

bool check2(int i){
  return taken[i-n]==1 && drop[i]==0 && cur>0;
}

void TRY(int k){
  for( int i=1; i<=2*n; i++){
    if( i <= n){
      if ( k!=2*n){
        if( check1(i) ){
          path[k]=i;
          taken[i]=1;
          dis+=dismap[path[k-1]][i];
          //cout << dis <<"|" << endl;
          cur++;
          lower=dis+cmin*(2*n-k+1);
          if(lower<mindis) TRY(k+1);
          dis-=dismap[path[k-1]][i];
          taken[i]=0;
          cur--;  
        }
      }
    }else{
      if( check2(i) ){
        path[k]=i;
        drop[i]=1;
        cur--;  
        dis+=dismap[path[k-1]][i];
        //cout << dis << endl;
        if(k==2*n) {
          mindis=min(mindis,dis+dismap[i][0]);
          // for(int j=0; j<=2*n; j++){
          //   cout << path[j] << " ";
          // }
        }
        else{
          lower=dis+cmin*(2*n-k+1);
          if(lower<mindis) TRY(k+1);
        }
        dis-=dismap[path[k-1]][i];
        drop[i]=0;
        cur++;
      }
    }
  }
}

int main(){
  cin >> n >> h;
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
  }
  for( int i=0; i<30; i++) {
    path[i]=0;
    drop[i]=0;
  }
  TRY(1);
  cout << mindis;
  return 0;
}