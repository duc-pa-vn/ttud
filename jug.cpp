#include<bits/stdc++.h>
using namespace std;

#define MAX 901
int a,b,c;
bool check[MAX][MAX]={false};
int cnt[MAX][MAX];
queue< pair<int,int> > q;
int flag=0;

int main(){
  cin >> a >> b >> c; 
  q.push({0,0});
  check[0][0]=true;
  cnt[0][0]=0;

  while(!q.empty()){
    pair<int,int> p=q.front();
    q.pop();
    int x=p.first;
    int y=p.second;
    if( p.first==c || p.second==c ){
      cout << cnt[p.first][p.second];
      flag=1;
      break;
    }
    if( !check[0][y]){
      q.push({0,y});
      check[0][y]=true;
      cnt[0][y]=cnt[x][y]+1;
    }
    if( !check[x][0]){
      q.push({x,0});
      check[x][0]=true;
      cnt[x][0]=cnt[x][y]+1;
    }
    if( !check[x][b]){
      q.push({x,b});
      check[x][b]=true;
      cnt[x][b]=cnt[x][y]+1;
    }
    if( !check[a][y]){
      q.push({a,y});
      check[a][y]=true;
      cnt[a][y]=cnt[x][y]+1;
    }
    if( x>0 ){
      if(!check[max(0,x+y-b)][min(x+y,b)]){
        q.push({max(0,x+y-b),min(x+y,b)});
        check[max(0,x+y-b)][min(x+y,b)]=true;
        cnt[max(0,x+y-b)][min(x+y,b)]=cnt[x][y]+1;
      }
    }
    if( y>0 ){
      if(!check[min(x+y,a)][max(x+y-a,0)]){
        q.push({min(x+y,a),max(x+y-a,0)});
        check[min(x+y,a)][max(x+y-a,0)]=true;
        cnt[min(x+y,a)][max(x+y-a,0)]=cnt[x][y]+1;
      }
    }
  }
  if(!flag) cout << -1;
  return 0;

}