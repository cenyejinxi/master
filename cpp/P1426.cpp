#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,c=0,s=7;
	cin>>a>>b;
	while(c<a-b){
		c+=s;
		s=s*0.98;
	}
	if(c+s>a+b){
		cout<<"n";
		return 0;
	}
	cout<<"y";
	return 0;
}
