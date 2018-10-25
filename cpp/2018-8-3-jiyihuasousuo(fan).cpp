#include<bits/stdc++.h>
using namespace std;
#define MAXN 5001
int A[MAXN][MAXN],F[MAXN][MAXN],n,maxx;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>A[i][j];
		}
	}
	F[1][1]=A[1][1];
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			F[i][j]=max(F[i+1][j],F[i+1][j+1])+A[i][j];
		}
	}
	cout<<F[1][1];
	return 0;
}
