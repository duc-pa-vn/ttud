#include <bits/stdc++.h>
using namespace std;
#define M 100001

vector<int> A[M], A1[M];
int n, m, idx = 0, x[M], icc[M], ncc = 0;
char color[M];

void DFSA(int i){
    color[i] = 'G';
    for( int j = 0; j < A[i].size(); j++){
        int v = A[i][j];
        if( color[v] == 'W'){
            DFSA(v);
        }
    }
    color[i] = 'B';
    idx++;
    x[idx] = i;
}

void DFSA(){
    for( int i = 1; i <= n; i++) {
        color[i] = 'W';
    }
    for( int i = 1; i <= n; i++){
        if( color[i] == 'W' ) {
            DFSA(i);
        }
    }
}

void DFSA1(int i){
    color[i] = 'G';
    //cout << i << endl;
    icc[i] = ncc;
    for( int j = 0; j < A1[i].size(); j++){
        int v = A1[i][j];
        if(color[v] == 'W'){
            DFSA1(v);
        }
    }
    color[i] = 'B';
}

void DFSA1(){
    for( int i = 1; i <= n; i++){
        color[i] = 'W';
    }
    for( int i = n; i >= 1; i--){
        if( color[x[i]] == 'W'){
            ncc++;
            DFSA1(x[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    int z, y;
    for( int i = 1; i <= m; i++){
        cin >> z >> y;
        A[z].push_back(y);
        A1[y].push_back(z);
    }
    DFSA();
    DFSA1();
    cout << ncc;
    return 0;
}
