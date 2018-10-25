#include<bits/stdc++.h>
using namespace std;
int lifetime[1000000]={0},mem[1000000]={0};
int main(){
//	freopen("P1540.in","r",stdin);
	int m,n,temp,cur,curmax,cnt=0;
	bool flag;
	cin>>m>>n;
	ios::sync_with_stdio(false);
	for(int i=0;i<n;i++){
		cin>>temp;
		flag=false;
		for(int i=0;i<m;i++){
			if(temp==mem[i]){
				flag=true;
				break;
			}
		}
		for(int i=0;i<m;i++){
			lifetime[i]++;
		}
		if(flag){
			continue;
		}
		else{
			cur=0;
			curmax=lifetime[0];
			for(int i=0;i<m;i++){
				if(lifetime[i]>curmax){
					cur=i;
					curmax=lifetime[i];
				}
			}
			mem[cur]=temp;
			lifetime[cur]=1;
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
