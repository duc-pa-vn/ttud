#include <bits/stdc++.h>
using namespace std;
#define M pair<long,long>
int n,k,c,mark;

bool compairPair(M a, M b){
    return a.first < b.first;
}
int main(){
    unsigned long long s = 0;
    unsigned long long temp =0;
    cin >> n >> k;
    M x[n];
    c =  0;
    for(int i = 0; i < n; i++){
        cin >> x[i].first >> x[i].second;
    }
    sort(x,x+n,compairPair);
    /*for(int i = 0; i < n; i++ ){
        cout << x[i].first << x[i].second <<endl;
    }*/
    mark = 0;
    for(int i = 0;i < n;i++){
        if(x[i].first < 0) {
            if(c < x[i].second ){
                x[i].second -= c;
                if ( x[i].second % k == 0 ){
                temp = (x[i].second/k) *2;
                temp *= abs(x[i].first);
                s += temp;
                c =0;
                }
                else {
                    temp = (x[i].second/k + 1) *2;
                    temp *= abs(x[i].first);
                    s += temp;
                    c = k - x[i].second % k;
                }
                continue;
            }else{
                c -= x[i].second;
                continue;
            }
        }
        else break;
    }
    c = 0;
    for(int i = n-1;i >= 0;i--){
        if(x[i].first > 0){
            if(c < x[i].second ){
                x[i].second -= c;
                if ( x[i].second % k == 0 ){
                    temp = (x[i].second/k) *2;
                    temp *= x[i].first;
                    s += temp;
                    c =0;
                }
                else {
                    temp = (x[i].second/k + 1) *2;
                    temp *= x[i].first;
                    s += temp;
                    c = k - x[i].second % k;
                }
                continue;
            }else{
                c -= x[i].second;
                continue;
            }
        }else break;

    }
    cout << s << endl;
    return 0;
}





