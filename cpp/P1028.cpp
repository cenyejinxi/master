#include<bits/stdc++.h>
using namespace std;
int fkg[1001];
void run(int a){
	int s=a/2;
	fkg[a]=s;
	for(int i=1;i<s+1;i++)
		{fkg[a]+=fkg[i];}
}
int main(){
	for(int i=1;i<=1000;i++)
		run(i);
	int k;
	cin>>k;
	cout<<fkg[k]+1;
	return 0;
}
