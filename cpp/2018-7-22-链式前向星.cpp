#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
int head[MAXN],idx;
struct Node{
	int next,w,to; 
}edge[MAXN];
void addEdge(int from,int to,int w){
	edge[idx].to=to;
	edge[idx].w=w;
	edge[idx].next=head[from];
	head[from]=idx;
	idx++; 
}
int main(){
	int n;
	ios::sync_with_stdio(false) 
	cin>>n;
	int a,b,c;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		addEdge(a,b,c); 
	}
	return 0;
} 
