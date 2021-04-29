const int N = 1e6 + 1;
int n ,m ;
vector<int> A[N];
int ncc;
int icc[N];
char color[N];

void input(){
	cin >> n >> m;
	for( int k = 1; k <= m; k++){
	int u,v;
	cin >> u >> v;
	A[v].push_back(u);
	A[u].push_back(v);
	}
} 
void DFS(u){
	color[u] = 'G';
	icc[u] = ncc;
	for( int i = 0; i < A[u].size(); i++){
		int v = A[u][i];
		if(color[v] = 'W'){
			DFS(v);
		}	
	}
}
