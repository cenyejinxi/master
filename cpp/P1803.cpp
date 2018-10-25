#include<bits/stdc++.h>
using namespace std;
struct match{
	int timestamp,end;
};
struct cmp{
	bool operator()(match &a,match &b){
		return a.timestamp>b.timestamp||(a.timestamp==b.timestamp&&a.end>b.end);
	}
};
priority_queue<match,vector<match>,cmp>pq;
int main(){
	int counter,t1,t2,current,total=1;
	cin>>counter;
	for(int i=0;i<counter;i++){
		cin>>t1>>t2;
		pq.push({t1,t2});
	}
	match temp=pq.top();
	pq.pop();
	current=temp.end;
	while(!pq.empty()){
		match temp=pq.top();
		pq.pop();
		if(temp.timestamp<current)continue;
		total++;
		current=temp.end;
	}
	cout<<total;
	return 0;
}
