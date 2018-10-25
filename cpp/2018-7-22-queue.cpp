#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(){
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		q.push(a); 
	}
	while(!q.empty()){
		cout<<q.front();
		q.pop();
		if(!q.empty()){
			q.push(q.front());
			q.pop();
		}
	}
	return 0;
} 
