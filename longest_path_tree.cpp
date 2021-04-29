#include <bits/stdc++.h>
using namespace std;
const int N  = 1e5 + 1;
vector<int> A[N];
vector<int> c[N];
int n,m;
int d[N];
void input(){
    cin >> n ;
    m = n-1;
    for(int k = 1; k <= m; k++){
        int u,v,w;
        cin >> u >> v >> w;
        A[u].push_back(v);
        c[u].push_back(w);
        A[v].push_back(u);
        c[v].push_back(w);
    }
}
void init(){
    for(int v = 1; v <= n; v++) d[v] = -1;
}
void dfs(int u){
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i];// v la 1 dinh ke cua u
        int w = c[u][i];// w la trong so canh (u,v)
        if(d[v] == -1){
                d[v] = d[u] + w;
                dfs(v);
        }
    }
}
void solve(){
    init();
    int s = 1;
    d[s] = 0;
    dfs(s);
    int x = -1;
    int D = 0;
    for(int v = 1; v <= n; v++) if(d[v] > D){
        D = d[v]; x = v;
    }

    init();
    d[x] = 0;
    dfs(x);
    int y = -1;
    D = 0;
    for(int v = 1; v <= n; v++) if(d[v] > D){
        D = d[v]; y = v;
    }
    cout << D;
}
int main(){
    input();
    solve();
}
