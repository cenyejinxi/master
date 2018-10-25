#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int a,b,c;
	cin>>a;
	while(a!=0){
		b=b*10+a%10;
		a=a/10;
	}
	cout<<b;
	return 0;
} 
