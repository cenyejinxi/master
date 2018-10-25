#include<bits/stdc++.h>
using namespace std;
int main(){
	string temp;
	int en;
	int a[26];
	memset(a,0,sizeof(a));
	for(int i=0;i<=3;i++){
		scanf("%s",&temp);
		en=0;
		while(temp[en]=='\0'){
			cout<<temp[en]; 
			if('A' <= temp[en] <= 'Z'){
				a[temp[en]-'A']++;
			}
			en++;
		}
	}
	int curmax=0;
	for(int i=0;i<26;i++){
		curmax=max(curmax,a[i]);
	}
	for(int i=curmax;i>=1;i--){
		for(int j=0;j<26;j++){
			if(a[j]>=i){
				cout<<"*";
			}
			else{
				cout<<" ";
			}
			cout<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<26;i++){
		cout<<'A'+i<<" ";
	}	
	return 0;
}
