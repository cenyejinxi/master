#include<bits/stdc++.h>
using namespace std;
bool vis[102];
int dis[102],n,curmin=INT_MAX;
int nxt(int i){
	if(i==n-1){
		return n-2;
	}
	if(i==0){
		return 1;
	}
	if(2*dis[i]>dis[i+1]+dis[i-1]){
		return i-1;
	}
	return i+1;
}
void dfs(int step,int localpoint){
	bool flag=true,lvis[102];
	for(int i=0;i<n;i++){
		lvis[i]=vis[i];
	}
	while(vis[localpoint]==false){
		vis[localpoint]=true;
		localpoint=nxt(localpoint);
	}
	for(int i=0;i<n-1;i++){
		if(vis[i]==false){
			flag=false;
			break;
		}
	}
	if(flag==true){
		curmin=min(curmin,step+1);
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]==false){
			dfs(step+1,i);
		}
	}
	for(int i=0;i<n;i++){
		vis[i]=lvis[i];
	}
}
int main(){
//	freopen("hoofball.in","r",stdin);
//	freopen("hoofball.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>dis[i];
	}
	for(int i=0;i<n;i++){
		dfs(0,i);
	}
	for(int i=0;i<n;i++){
		if (i<nxt(i) && nxt(nxt(i))==i && ((int)nxt(i-1)==i) + ((int)nxt(i+1)==i) ==1 && ((int)nxt(nxt(i)-1)==i) + ((int)nxt(nxt(i)+1)==i) ==1){
			curmin++;
		}
	}
	cout<<curmin;
	return 0;
}
