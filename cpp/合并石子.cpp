#include<bits/stdc++.h>
using namespace std;
int f[101][101];
int main(){
	int n,a[101]={0},s[101]={0};
	cin>>n;
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=n-1;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<=j-1;k++){
			f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}
