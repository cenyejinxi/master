#include<bits/stdc++.h>
using namespace std;
int s,len,ans=1,maxl,localer;
int main(){
	cin>>len>>maxl;
	for(int i=0;i<len;i++){
		cin>>s;
		if(localer+s<maxl)localer+=s;
		else if(localer+s==maxl){localer=0;ans++;}
		else{localer=s;ans++;}
	}
	cout<<ans;
	return 0;
}
