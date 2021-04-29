#include <bits/stdc++.h>
using namespace std;
const int TU = 11111;
int dist[11111], N, K, c[TU], d[TU], p[TU], check[5001][5001];
vector<int> road[TU];
vector< vector< int > > nmap;

int color[TU], dd[TU];

void BFS(int u){
  dd[u] = 0;
  queue<int> q;
  q.push(u);
  color[u] = 1;
  int v;
  while( !q.empty()){
    v = q.front();
    q.pop();
    for( auto &x : road[v]){
      //cout << v << " " << x << endl;
      if( color[x] ==0 ){
        dd[x] = dd[v] + 1;
        if(dd[x] <= d[u]){
          if(check[u][x] == 0){
            int p;
            p = x;
            //cout << u << " " << p.first << " " << p.second << endl;
            nmap[u].push_back(p);
            check[u][x] = 1;
          }
        }
        color[x] = 1;
        q.push(x);
      }
    }
  }
}

void BFS(){
  for( int i = 1; i <= N; i++){
      color[i] = 0;
  }
  for( int i = 1; i <= N; i++){
    BFS(i);
    for( int i = 1; i <= N; i++){
      color[i] = 0;
      dd[i] = 0;
    }
  }
}

int dijkstra(const vector< vector< int > >&adj) {
    int len = adj.size();
    int d[len];
    //int p[len];
    d[1] = 0;
    for( int i = 2; i < len ; i++){
      d[i] = 99999999;
    }
    int cc[len][len];
    for( int i = 1; i < len; i++){
      for( int j = 1; j < len; j++){
        cc[i][j] = 99999999;
      }
    }
    for( int i = 1; i < len; i++){
      for( auto &it : adj[i]){
        cc[i][it] = c[i];
      }
    }
    for( auto &it : adj[1]){
      d[it] = c[1];
    }
    set<int> S;
    for( int i = 2; i < len; i++){
      S.insert(i);
    }
    while(!S.empty()){
      int u = *S.begin();
      for( auto &it : S){
        u = d[u] > d[it] ? it : u;
      }
      S.erase(u);
      for( auto &it : S){
        if( d[it] > d[u] + cc[u][it]){
          d[it] = d[u] + cc[u][it];
        }
      }
    }
    return d[len-1];
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> N >> K;
  for( int i = 1; i <= N; i++){
    cin >> c[i] >> d[i];
  }
  int x, y;
  for( int i = 1; i <= K; i++){
    cin >> x >> y;
    road[x].push_back(y);
    road[y].push_back(x);
  }
  memset(check,0,sizeof(check));

  nmap.resize(N+1);
  BFS();
  int ans= dijkstra(nmap);
  cout << ans;
return 0;
}
