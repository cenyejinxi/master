#include<bits/stdc++.h>
using namespace std;
struct jp{
	int v,w;
}l[2000];
int len;
int USSR[2000][6000];
int f[6000];
int main(){
	int n,m,v,w,s,r=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>v>>w>>s;
		while(s!=0){
			if(s>=r){
				l[len].v=v*r;
				l[len].w=w*r;
				s-=r;
				r*=2;
			}
			else{
				l[len].v=v*s;
				l[len].w=w*s;
				s=0;
				r=1;
			}
			len++;
		}
	}
	for(int i=0;i<len;i++){
		for(int j=m;j>=l[i].v;j--){
			f[j]=max(f[j],f[j-l[i].v]+l[i].w);
		}
	}
	cout<<f[m];
	return 0;
}
