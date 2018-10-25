#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		a[k]+=1;
	}
	for(int i=0;i<101;i++){
		for(int j=0;j<a[i];j++){
			cout<<i<<" ";
		}
	}
	return 0;
}
