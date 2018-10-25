#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int> >pq;
int main(){
	freopen("souvenir.in","r",stdin);
	freopen("souvenir.out","w",stdout);
	int n,m,lk=0,t=0,cnt=1,lkcnt=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>t;
		pq.push(t);
	}
	for(int i=0;i<m;i++){
		t=pq.top();
		pq.pop();
		if(lkcnt==2){
			lkcnt=1;
			cnt++;
			lk=t;
		}
		else if(lk+t>n){
			cnt++;lkcnt=1;
			lk=t;
		}
		else if(lk+t==n){
			cnt++;lkcnt=0;
			lk=0;
		}
		else{
			lkcnt++;
			lk=t;
		}
	}
	if(lkcnt){
		cnt++;
	} 
	cout<<cnt;
	return 0;
}
