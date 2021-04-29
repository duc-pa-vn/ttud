#include <bits/stdc++.h>
using namespace std;
string ans ;
int i = 0;

void changebase( int base, int num){
    if(num == 0) ;
    else{
        ans += pow(10,i)*(num%base);
        i++;
        changebase(base,num/base);
    }
}

int main(){
    changebase(2,55);
    cout << ans;
}
