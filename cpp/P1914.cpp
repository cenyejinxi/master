#include<bits/stdc++.h>
using namespace std;
int main(){
	string temp;
	int n,k=0;
	cin>>n;
	cin>>temp;
	while(temp[k]!='\0'){
		printf("%c",(temp[k]-'a'+n)%26+'a');
		k++;
	}
}
