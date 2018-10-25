#include<bits/stdc++.h>
using namespace std;
bool isprime(int j){
	for(int i=2;i<=sqrt(j);i++){
		if(j%i==0){
			return false;
		}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	for(int i1=2;i1<n-4;i1++){
		for(int i2=2;i2<n-4;i2++){
			if(isprime(i1) && isprime(i2) && isprime(n-i1-i2)){
				cout<<i1<<" "<<i2<<" "<<n-i1-i2;
				return 0; 
			}
		}
	}
}
