
#include <bits/stdc++.h>
using namespace std;
#define M 100001
int n , m, d[M], ans = 1;
vector<int> A[M];

void BFS( int u){
   queue<int> q;
   q.push(u);
   d[u] = 0;
   while(!q.empty()){
     int top = q.front();
     q.pop();
     for( int i = 0; i < A[top].size(); i++){
       int v = A[top][i];
       if( d[v] == -1){
         d[v] = d[top]?0:1;
         q.push(v);
       }
       else{
         if( d[top] == d[v] ) ans = 0;
       }
     }
   }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    int x, y;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    for( int i = 1; i <= n; i++) d[i] = -1;
    for( int i = 1; i <= n; i++){
        if(d[i] == -1){
            BFS(i);
        }
    }
    cout << ans;
    return 0;
}
