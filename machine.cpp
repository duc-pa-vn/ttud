#include<bits/stdc++.h>
using namespace std;

int n, ans, a[222222];
pair<int, int>  input[222222];
queue<int> q;

int main(){
    cin >> n;
    pair< int , int> p;
    for( int i = 0; i < n; i++){
        cin >> p.first.first;
        cin >> p.first.second;
        p.second = p.first.second - p.first.first;
        input[i] = p;
    }
    // cout << input[2].first.first;
    sort(input,input+n+1,[] (pair< pair<int, int> ,int> p1, pair< pair<int, int>, int > p2){
      return p1.first.first < p2.first.first;
    });
    for( int i = 1; i < n ; i++){
        if( input[i-1].first.second < input[i].first.first)
        a[i] = max(,a[i-1]+input[i].second);

      ans = max(ans,a[i]);
    }
    cout  << ans;
    return 0;
}

