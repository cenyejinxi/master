#include<bits/stdc++.h>
using namespace std;
int counter;
#define MAXN 100000
long long a[MAXN],b[MAXN];
priority_queue<long long int,vector<long long int>,greater<long long int> >pq;
int main(){
	cin>>counter;
	for(int i=0;i<counter;i++)cin>>a[i];
	for(int i=0;i<counter;i++)cin>>b[i];
	for(int i=0;i<counter;i++){
		for(int j=0;j<counter;j++){
			pq.push(a[i]+b[j]);
		}
	}
	for(int i=0;i<counter;i++){
		cout<<pq.top()<<" ";
		pq.pop(); 
	}
	return 0;
}
