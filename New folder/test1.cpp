#include<bits/stdc++.h>
using namespace std;

int n, a[999999], ans = 1, remem;

int main(){
	cin >> n;
	for( int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	remem = a[1];
	
	for( int i = 2; i <= n; i++){
		if( a[i] > remem ) {
			remem = a[i];
		}
		else{
			remem = a[i];
			ans++;
		}
	}
cout << ans;
	return 0;	
}