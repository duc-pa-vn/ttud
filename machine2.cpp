#include<bits/stdc++.h>
using namespace std;
#define MAX 111111
int ti[MAX], n, maxt[MAX], cur = 1,flag = 0 ;
pair< int, int> gt[MAX],st[MAX];

int main(){
    cin >> n;
    int ans;
    for( int i = 1; i <= n; i++){
        pair<int, int> p;
        cin >> p.first >> p.second;
        st[i] = p;
    }
    sort(st+1,st+n+1,[](pair<int, int> p1, pair<int, int> p2){
            return p1.first <= p2.first;
    });
    for( int i = 1; i <= n; i++){
        pair<int, int> p1;
        int time = st[i].second - st[i].first;
        ti[i] = time;
        p1.first = i;
        p1.second = time;
        gt[i] = p1;
    }
    sort(gt+1,gt+n+1,[](pair<int, int> p1, pair<int, int> p2){
            return p1.second <= p2.second;
    });
    maxt[1] = ti[1];
    ans = maxt[1];
    for( int i = 2; i <= n; i++){
        maxt[i] = maxt[i-1] - ti[i-1] + ti[i];
        while(st[i].first > st[gt[cur].first].second){
            maxt[i] = max(maxt[i], ti[i] + gt[cur].second);
            flag = 1;
            if( cur + 1> n) break;
            cur++;
        }
        ans = max(ans, maxt[i]);
        //cout << maxt[i] << endl;
    }
    if(flag ==1)cout << ans;
    else cout <<  -1;
}

