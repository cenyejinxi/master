#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("teleport.in","r",stdin);
	freopen("teleport.out","w",stdout);
	int x,y,a,b;
	cin>>x>>y>>a>>b;
	cout<<min(abs(x-y),min(abs(x-a)+abs(y-b),abs(x-b)+abs(y-a)));
	return 0;
}
