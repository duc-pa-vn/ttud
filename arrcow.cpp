#include<bits/stdc++.h>
using namespace std;

int N,C,x[999999],test;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> test;
    while(test--){
        cin >> N >> C;
        for(int i = 0 ; i < N ; i++){
            cin >> x[i];
        }
        sort(x,x+N);
        int l = 0, r = 1000000000;
        int m = (l + r)/2, pre_loc;
        while(m!=l){
            int count = 1;
            pre_loc = 0;
            for( int i = 1 ; i < N ; i++){
                if( (x[i]-x[pre_loc]) >= m ){
                    count++;
                    pre_loc = i; 
                }
            }
            if( count < C) r = m;
            else if( count >= C ) l = m;
            m = (l + r)/2;
        }
        cout << m << endl;
    }
    return 0;
}
