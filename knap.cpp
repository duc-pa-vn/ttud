#include<bits/stdc++.h>
using namespace std;

int n,b;
pair<int, int> listt[33];
long quanlity=0,maxquanlity=-1;
double upper;
double maxqpw=0;

bool check(int i,int k){
  return b>=i*listt[k].first;
}

void TRY(int k){
  for(int i=0; i<=1; i++){    
    if( check(i,k)){
      quanlity+=i*listt[k].second;
      b-=i*listt[k].first;
      if(k==n){
        if(quanlity>maxquanlity) maxquanlity=quanlity;
      }else{
        upper=(double) quanlity + b*maxqpw;
        if(upper>maxquanlity) TRY(k+1);
      }
      quanlity-=i*listt[k].second;
      b+=i*listt[k].first;
    } 
  }
}

int main(){
  cin >> n >> b;
  for( int i=1; i<=n; i++){
    cin >> listt[i].first >> listt[i].second;
  }
  double qpw[n];
  for( int i=1; i<=n; i++){
    qpw[i]=(double) listt[i].second/listt[i].first;
  }
  for( int i=1; i<=n; i++){
    if(qpw[i]>maxqpw) maxqpw=qpw[i];
  }
  TRY(1);
  cout << maxquanlity;
  return 0;
}