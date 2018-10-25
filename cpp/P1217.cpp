#include<bits/stdc++.h>
using namespace std;
int pr[10000000]={2},len=1;
void is_prime(int k){
	double s=sqrt(k);
	for(int i=0;i<len-1;i++){
		if(pr[i]>=s){
			return;
		}
		if(k%pr[i]==0){
			return;
		}
	}
	pr[len]=k;
	len++;
	return;
}
bool is_hw(int k){
	int sw[10],f=0,sk=k,r=0;
	while(sk!=0){
		sw[f]=sk%10;
		sk/=10;
		f++;
	}
	for(int i=0;i<f;i++){
		r=10*r+sw[f];
	}
	if(sk==r){
		return true;
	}
	return false;
}
int main(){
	for(int i=3;i<=100;i++){
		is_prime(i);
	}
	int m,n,temp;
	for(int fkg=0;fkg<100;fkg++)cout<<pr[fkg];
	cin>>m>>n;
	int idx;
	for(idx=0;pr[idx]<m;idx++){}
	temp=pr[++idx];
	while(temp<n){
		if(is_hw(temp))
		cout<<temp<<endl;
		temp=pr[++idx];
	}
	return 0;
}
