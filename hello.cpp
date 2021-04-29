#include<bits/stdc++.h>
using namespace std;

int  n, i, k;
int bin[999999];

bool check(int v, int h){
  if( v==0 ){
    if( h>=(i-1) ){
      for( int j=1; j<=i-1; j++){
        if( bin[h-j]==1) return true;
      }
      return false;
    }
    else return true;
  }
  else return true;
}

void TRY(int  h){
	for( int v=0; v<=1; v++){
		if(check(v,h)){
			bin[h]=v;
			if( h==n-1 ){
				k--;
				if( k==0 ){
					for(int j=0; j<n; j++){
						cout << bin[j] << " ";
					}
				}
			}
			else TRY(h+1);
		}
	}
}

int main(){
  cin >> n >> k >> i;
  TRY(0);
  if ( k>0 ) cout << -1;
  return 0;
}
