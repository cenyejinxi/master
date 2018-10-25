#include<bits/stdc++.h>
using namespace std;
struct thing{
	int v,p,q,child[3];
}things[60];
int f[32000],len; 
int main(){
	int n,m,v,p,q;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>v>>p>>q;
		things[len].q=q;
		things[len].v=v*p;
		things[len].p=p;
		if(p!=0)things[p]=len;
		len++;
	}
	for(int i=0;i<m;i++){
		if(things[len].q==0){
			for(int j=n;j>=things[i].v;j--){
				if(things[j].q!=0){
					f[j]=max(f[j],f[j-v[i]]+w[i]);
				}
			}
		}
	}
}
