#include<bits/stdc++.h>
using namespace std;
int N, Q=0, cnt, test;
map<char, int> A;
string B="HUSTOIC";
int visitted[10];
bool check(int i){
	return visitted[i]==0;
}

void TRY(int k){
  for( int i=0; i<=9; i++){
  	if(check(i)){
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
  for( int i=0; i<=9; i++){
    visitted[i]=0;
  }
cin >> N;
  TRY(0);  
  cout << Q << endl; 
}
  return 0;
}