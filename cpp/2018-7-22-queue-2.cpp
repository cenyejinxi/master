#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	while(n!=0 || m!=0){
		for(int i=1;i<=n;i++){
			q.push(i);
		}
		while(q.size()!=1){
			for(int i=1;i<m;i++){
				q.push(q.front());
				q.pop();
			}
			q.pop();
		}
		printf("%d\n",q.front());
		q.pop();
		scanf("%d%d",&n,&m); 
	} 
	return 0;
} 
