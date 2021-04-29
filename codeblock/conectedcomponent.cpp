#include <bits/stdc++.h>
using namespace std;
#define M 1000000
int visited[M], ans = 0, n , m;
vector<int> A[M];

void DFS( int u){
    for( int i = 0; i < A[u].size(); i++){
        int v = A[u][i];
        if(!visited[v]){
            visited[v] = 1;
            DFS(v);
        }
    }
}

int main(){
    cin >> n >> m;
    int x, y;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        A[x].push_back(y);
        A[y].push_back(x);
    }
    for( int i = 1; i <= n; i++) visited[i] = 0;
    for( int i = 1; i <= n; i++){
        if(!visited[i]){
            ans++;
            DFS(i);
        }
    }
    cout << ans;
}
