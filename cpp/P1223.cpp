#include<bits/stdc++.h>
using namespace std;
struct water{
	int no,timeusage;
};
struct cmp{
	bool operator()(water &a,water &b){
		return a.timeusage<b.timeusage;
	}
};
struct cmp1{
	bool operator()(water &a,water &b){
		return a.timeusage>b.timeusage||(a.timeusage==b.timeusage&&a.no>b.no);
	}
};
priority_queue<water,vector<water>,cmp>pq;
priority_queue<water,vector<water>,cmp1>pq1;
int no,counter,temp,c0;
long long int total;
int main(){
	cin>>counter;
	for(int i=1;i<=counter;i++){
		cin>>temp;
		pq1.push({i,temp});
		pq.push({i,temp});
	}
	while(!pq1.empty()){
		water tmp=pq1.top();
		pq1.pop();
		cout<<tmp.no<<" ";
	}
	while(!pq.empty()){
		water tmp=pq.top();
		pq.pop();
		total+=tmp.timeusage*c0;
		c0++;
	}
	cout<<endl;
	printf("%.2f",(double)total/counter);
}

