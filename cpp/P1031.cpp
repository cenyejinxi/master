#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int k[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>k[i];
		sum+=k[i];
	}
	int avg=sum/n;
	int times=0;
	for(int i=0;i<n-1;i++){
		if(k[i]==avg){
			continue;
		}
		times++;
		k[i+1]-=(avg-k[i]);
		k[i]=avg;
	}
	cout<<times;
	return 0;
}
