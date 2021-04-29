#include <bits/stdc++.h>
using namespace std;
int main(){
	unsigned long long a, b;
	cin >> a >>b;
	if(a<10 && b<10){
	    cout << a+b;
	}else{
    	unsigned long long c = a/10;
    	long long d = b/10;
    	int e = a%10;
    	int f = b%10;
    	if ( e+f >=10){	
    		unsigned long long r1 = c+d+1;
    		long long r2 = e+f-10;
    		cout << r1 << r2;
    	}else{
    		unsigned long long r3=c+d;
    		long long r4=e+f;
    		cout << r3 << r4;
    		}
	}		
    		return 0;
}