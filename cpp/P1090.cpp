#include<bits/stdc++.h>
using namespace std;
priority_queue<unsigned long long int,vector<unsigned long long int>,greater<unsigned long long int> > pq;
int main(){
	freopen("P1090.in","r",stdin);
	unsigned long long int n,k,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		pq.push(k);
	}
	for(int i=0;i<n-1;i++){
		unsigned long long int q1=pq.top();pq.pop();
		unsigned long long int q2=pq.top();pq.pop();
		sum+=q1+q2;
		pq.push(q1+q2);
	}
	cout<<sum;
	return 0;
}
