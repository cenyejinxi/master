#include<bits/stdc++.h>
using namespace std;
char a1[3]="()",a2[3]="{}",a3[3]="[]";
int main(){
	ios::sync_with_stdio(false);
	string a;
	cin>>a;
	stack<char> s; 
	for(int i=0;i<a.length();i++){
		char b=a[i];
		if(b=='('||b=='['||b=='{')
			s.push(b);
		else{
			char c[3];
			c[1]=b;
			c[0]=s.top();
			c[2]='\0';
			if(strcmp(a1,c)&&strcmp(a2,c)&&strcmp(a3,c)){
				cout<<"N"<<endl;
				return 0;
			}
			s.pop();
		} 
	}
	if(!s.empty()){
		cout<<"N"<<endl;
		return 0; 
	}
	cout<<"Y"<<endl;
	return 0;
}
