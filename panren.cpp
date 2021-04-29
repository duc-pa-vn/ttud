#include<bits/stdc++.h>
using namespace std;
string s;
int T;

int resolve( string s){
  stack<char> st;
  for(int i=0; i<s.length(); i++){
    if( s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
    else if( st.empty() || (s[i]==')' && st.top()!='(' ) || ( s[i]=='}' && st.top()!='{' ) || ( s[i]==']' && st.top()!='[')) {
      return 0;
    } else{
      st.pop();
    }
  }
  if(st.empty()) return 1;
  return 0;
}

int main(){
  cin >> T;
  for(int i=0; i<T; i++){
    cin >> s;
    cout << resolve(s) << endl;
  }
}