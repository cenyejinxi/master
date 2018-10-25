#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("antman.in","r",stdin);
	freopen("antman.out","w",stdout);
	int L,m,t1,t2;
	double ans=INT_MAX;
	cin>>L>>m;
	for(int i=0;i<m;i++){
		cin>>t1>>t2;
		if(t1 != 0 && t2*2 < L){
			ans=min(ans,(double)(L-t2)/t1);
		}
	}
	printf("%.2f",ans);
	return 0;
}
