#include<bits/stdc++.h>
using namespace std;
#define MAXN 200000;
priority_queue<int,vector<int>,greater<int> > pq,cmd2;
queue <int> cmd1;
int counter,last;
void get(){
    int k[counter];
    memset(k,0,sizeof(k));
    for(int i=0;i<counter;i++){
        k[i]=pq.top();
        pq.pop();
    }
    cout<<pq.top()<<endl;
    for(int i=0;i<counter;i++){
        pq.push(k[i]);
    }
    counter++;
    return;
}
int main(){
	freopen("P1801.in","r",stdin);
	freopen("P1801.outk","w",stdout);
    ios::sync_with_stdio(false);
    int a,b,k;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>k;
        cmd1.push(k);
    }
    for(int i=0;i<b;i++){
        cin>>k;
        cmd2.push(k);
    }
    while(!cmd2.empty()){
        for(int i=last;i<cmd2.top();i++){
            pq.push(cmd1.front());
            cmd1.pop();
        }
        last=cmd2.top();
        get();
        cmd2.pop();
    }
    return 0;
}
