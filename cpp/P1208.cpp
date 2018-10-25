#include<bits/stdc++.h>
using namespace std;
struct farm{
	int ppu,amount;//priceperunit
};
struct cmp{
	bool operator()(farm &a,farm &b){
		return a.ppu>b.ppu||(a.ppu==b.ppu&&a.amount>b.amount);
	}
};
priority_queue<farm , vector<farm>, cmp> farmlist;
int main(){
	int m,n,t1,t2;
	long long int sum=0;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		cin>>t1>>t2;
		farmlist.push({t1,t2});
	}
	while(m>0){
		farm temp=farmlist.top();
		farmlist.pop();
		if(temp.amount<=m){
			m-=temp.amount;
			sum+=temp.ppu*temp.amount;
		}
		else{
			sum+=m*temp.ppu;
			m=0;
		}
	}
	cout<<sum;
	return 0;
}
