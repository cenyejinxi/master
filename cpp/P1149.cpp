#include<bits/stdc++.h>
using namespace std;
int sl[]={6,2,5,5,4,5,6,3,7,6};
int get(int a){
	int t=0;
	if(a==0){
		return 6;
	}
	while(a!=0){
		t+=sl[a%10];
		a/=10;
	}
	return t;
}
int main(){
	int n,x,cnt=0;
	cin>>n;
	n-=4;
	for(int i=0;i<=1111;i++){
		for(int j=0;j<1111;j++){
			x=i+j;
			if(get(i)+get(j)+get(x)==n){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
