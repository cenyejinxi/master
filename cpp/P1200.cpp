#include<bits/stdc++.h>
using namespace std;
int main(){
	string ti,tr;
	int s1=1,s2=1;
	cin>>ti>>tr;
	for(int i=0;i<ti.length();i++){
		s1*=ti[i]-'@';
	}
	for(int i=0;i<tr.length();i++){
		s2*=tr[i]-'@';
	}
	if((s1-s2)%47){
		cout<<"STAY";
		return 0;
	}
	cout<<"GO";
	return 0;
}
