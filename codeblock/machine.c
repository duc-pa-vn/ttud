#include<bits/stdc++.h>
using namespace std;

int n, ans, a[222222];
pair< pair<int, int> , int> input[222222];

int main(){
    cin >> n;
    pair< pair< int , int> , int > p;
    for( int i = 0; i < n; i++){
        cin >> p.first.first;
        cin >> p,first,second;
        p.second = p.first.second - p.first.first;
        input[i] = p;
    }
    cout << input[2].first.first;
    return 0;
}

