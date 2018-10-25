#include<bits/stdc++.h>
using namespace std;
int a[100],b[100];
int main(){
	freopen("outofplace.in","r",stdin);
	freopen("outofplace.out","w",stdout);
	int n,cnt=-1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	bool flag=false;
	sort(b,b+n);
	for(int i=0; i<n; i++) {
			if(a[i]!=b[i]) {
				cnt++;
			}
	}
	cout<<max(cnt,0);
	return 0;
}
