#include<bits/stdc++.h>
using namespace std;
int a[41],n,k;
long long int g[41][41],f[41][6];
long long int get(int left,int right){
	long long int ans=0;
	for(int i=left;i<=right;i++){
	ans=ans*10+a[i];
	}
	return ans;
}
long long int maxx(long long int a,long long int b){
	if(a>=b)return a;
	return b;
}
int main(){
	char temp;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>temp;
		a[i]=temp-'0';
		g[i][i]=a[i]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			g[j][i]=get(j,i);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<" "<<j<<":"<<g[i][j]<<endl;
//		}
//	}
	for(int i=1;i<=n;i++){
		f[i][0]=g[1][i];
	}
	for(int j=1;j<=k;j++)
		for(int i=j+1;i<=n;i++)
			for(int s=j;s<i;s++)
				f[i][j]=maxx(f[i][j],f[s][j-1]*g[s+1][i]);
	cout<<f[n][k];
	return 0;		
}
