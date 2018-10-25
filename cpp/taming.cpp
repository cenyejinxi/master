#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("taming.in","r",stdin);
	freopen("taming.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,j;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int breakout[n];
	for(int i=1;i<n;i++){
		breakout[i]=0;
	}
	breakout[0]=1;
	for(int i=1;i<n;i++){
		if(a[i]==0){
			breakout[i]=0;
		}
		if(a[i]>0){
			for(j=i;i-j+1<=a[i];j--){
				breakout[j]=-1;
			}
			breakout[j-1]=1;
		}
	}
	int fa=0,fb=0;
	for(int i=0;i<n;i++){
		if(breakout[i]==0){
			fa++;
		}
		if(breakout[i]==1){
			fb++;
		}
	}
	cout<<fb<<" "<<fa+fb;
	return 0;
}
