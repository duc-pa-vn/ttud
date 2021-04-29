#include<bits/stdc++.h>
using namespace std;
int N, Q=0, cnt, test;
map<char, int> A;
string B="HUSTOIC";
int visitted[10];
bool check(int i, int k){
	if( k == 0 || k == 2){
		if(i == 0) return false;
	}
	if( visitted[i] ==1) return false;
	return true;
}

void TRY(int k){
  for( int i=0; i<=9; i++){
  	if(check(i,k)){
	    A[B[k]]=i;
		visitted[i]=1; 
	    if( k==6 ){
	      if( (A[B[0]]*1000+A[B[1]]*100+A[B[2]]*10+A[B[3]] +A[B[2]]*10000+A[B[4]]*1000+A[B[5]]*100+A[B[6]]*10+A[B[3]] )==N ) Q++;
	    }
	    else TRY(k+1);
	    visitted[i]=0;
	}
  }
}

int main(){
  cin >> test;
while(test--){
  Q = 0;
  for( int i=0; i<=9; i++){
    visitted[i]=0;
  }
cin >> N;
  TRY(0);  
  cout << Q << endl; 
}
  return 0;
}