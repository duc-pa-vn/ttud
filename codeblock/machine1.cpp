#include<bits/stdc++.h>
using namespace std;

int n, ans, a[222222], tmin = 999999;
pair< pair<int, int> , int> input[222222];
deque<int> dq;
stack<int> s;

int main(){
    cin >> n;
    pair< pair< int , int> , int > p;
    for( int i = 0; i < n; i++){
        cin >> p.first.first;
        cin >> p.first.second;
        tmin = min(p.first.second,tmin);
        p.second = p.first.second - p.first.first;
        input[i] = p;
    }
    // cout << input[2].first.first;
    sort(input,input+n,[] (pair< pair<int, int> ,int> p1, pair< pair<int, int>, int > p2){
      return p1.first.first < p2.first.first;
    });
    if( tmin > input[n-1].first.first) {
      cout << -1;
      exit(0);
    }
    a[0] = 0;
    dq.push_back(0);
    for( int i = 1; i < n ; i++){
      if( a[i-1] == 0) a[i] =0;
      else a[i] = a[i-1] - input[i-1].second + input[i].second;
      if( input[i].first.second < input[dq.front()].first.second ) {
            dq.push_front(i);
            continue;
      }
      while( input[i].first.first > input[dq.front()].first.second ){
        a[i] = max(a[i],input[i].second + input[dq.front()].second);
        dq.pop_front();
      }
      while( input[i].first.second < input[dq.back()].first.second){
        s.push(dq.back());
        dq.pop_back();
      }
      dq.push_back(i);
      while( !s.empty() ){
        dq.push_back(s.top());
        s.pop();
      }
      ans = max(ans,a[i]);
    }
    cout  << ans;
    return 0;
}

