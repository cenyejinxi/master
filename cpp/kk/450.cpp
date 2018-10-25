#include<bits/stdc++.h>
using namespace std;
int df[200005],dg[200005],dk[200005];
int main(){
	int n,ans=0,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>df[i];
	}
	for(int i=1;i<=n;i++){
		dg[i]=max(dg[i-1],0)+df[i];
		if(dg[i]>ans){
			k=i;
		}
		ans=max(ans,dg[i]);
		if(dg[i-1]<=0){
			dk[i]=i;
		}
		else{
			dk[i]=dk[i-1];
		}
	}
	if(ans<=0){
		cout<<0;
		return 0;
	}
	if(k<=dk[k]){
		cout<<ans<<" "<<k-1<<" "<<dk[k]-1;
		return 0;
	}
	cout<<ans<<" "<<dk[k]-1<<" "<<k-1;
	return 0;
}
