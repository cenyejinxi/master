#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int book[1000000],reader[1000000][2];
int p(int a,int b){
	int s=1;
	for(int i=0;i<b;i++){
		s*=a;
	}
	return s;
}
bool match(int n1,int n2,int l){
	
	if(n1%p(10,l-1)==n2){
		return true;
	}
	return false;
}
priority_queue<int,vector<int>,greater<int> >pq;
int main(){
	ios::sync_with_stdio(false);
//	freopen("librarian.in","r",stdin);
//	freopen("librarian.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t;
		pq.push(t);
	}
	for(int i=0;i<n;i++){
		book[i]=pq.top();
		pq.pop();
	}
	for(int i=0;i<m;i++){
		cin>>reader[i][0];
		cin>>reader[i][1];
	}
	bool flag;
	for(int i=0;i<m;i++){
		flag=false;
		for(int j=0;j<n;j++){
			if(match(book[j],reader[i][1],reader[i][0]));{
				cout<<book[j]<<endl;
				j=n;
				flag=true;
			}
		}
		if(!flag){
			cout<<-1<<endl;
		}
	}
	return 0;
}
