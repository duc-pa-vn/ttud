#include<bits/stdc++.h>
using namespace std;

int  n, i, k, zero=0;
int bin[999999], flag;

void TRY(int  h){
	for( int v=0; v<=1; v++){
    // if(k == 0) return;
		if( v != 0 || zero != i-1){
			bin[h]=v;
      flag=zero;
      if( v== 0) zero++;
      else{
        zero=0;
      }
			if( h==n-1 ){
				k--;
				if( k==0 ){
					for(int j=0; j<n; j++){
						cout << bin[j] << " ";
					}
          exit(0);
				}
			} 
			else TRY(h+1);
      zero = flag;
		}
	}
}

int main(){
  cin >> n >> k >> i;
  TRY(0);
  if ( k>0 ) cout << -1;
  return 0;
}