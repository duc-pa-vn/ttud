#include<bits/stdc++.h>
using namespace std;

int n, b[999999], len, dino;
stack<int> s;
queue<int> q;
string sig;

int main(){
  cin >> n;
  for( int i = 1; i <= n; i++){
    cin >> b[i];
  }
  for( int i = n; i >= 1; i--){
    s.push(b[i]);
  }
  cin >> sig;
  len = sig.size();
  for( int i = 0; i < len; i++){
    if( sig[i] == 'C') {
      dino = s.top();
      s.pop();
      q.push(dino);
    }
    if( sig[i] == 'H'){
      dino = q.front();
      q.pop();
      s.push(dino);
    }
  }
  for( int i = 1; i <= n; i++){
    dino = s.top();
    cout << dino << " ";
    s.pop();
  }
  return 0;
}