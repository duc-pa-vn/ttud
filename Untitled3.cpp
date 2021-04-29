#include <bits/stdc++.h>
using namespace std;
#define N 1005
vector < pair<int,int> > a, b;
int L, C,T;
int cnt[2*N][2*N];

int Max(int A[2*N][2*N], unsigned int n, unsigned int m) {
    long int temp = A[0][0];
    for(unsigned int i = 0; i<n; i++)
    for(unsigned int j = 0; j<m; j++)
        if(temp <A[i][j])
            temp = A[i][j];
    return temp;        
}

int main(){
	cin >> T;
	while(T--){
		int u, v;
		cin >> L >> C;
		for(int i=0 ; i <L ; i++)
			for(int j=0 ; j <C ; j++){
				cin >> u;
				if (u) a.push_back({i,j});
			}
		
		for(int i=0 ; i <L ; i++)
			for(int j=0 ; j <C ; j++){
				cin >> v;
				if (v) b.push_back({i,j});
			}
		for(auto &u: a)
			for(auto &v: b){
				int delta_x = v.first - u.first + N;
				int delta_y = v.second - u.second + N;
				cnt[delta_x][delta_y]++; 
			}
		int res = Max(cnt,2*N,2*N);
		cout << res << endl;
    a.clear();
    b.clear();
    for(int i=0 ; i<2*N ; i++ )
      for(int j=0 ; j<2*N ; j++)
        cnt[i][j]=0;
	}
  return 0;
}

