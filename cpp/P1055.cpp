#include<bits/stdc++.h>
using namespace std;
int main(){
	char temp;
	int total=0;
	int a[10];
	for(int i=0;i<10;i++){
		cin>>temp;
		if(temp=='-')
		cin>>temp;
		a[i]=temp-'0'; 
	}
	for(int i=1;i<=9;i++){
		total+=a[i-1]*i;
	}
	if(total%11==a[9]){
		cout<<"Right";
		return 0;
	}
	if(total%11==10){
		cout<<a[0]<<"-"<<a[1]<<a[2]<<a[3]<<"-"<<a[4]<<a[5]<<a[6]<<a[7]<<a[8]<<"-"<<"X"; 
		return 0;
	}
	cout<<a[0]<<"-"<<a[1]<<a[2]<<a[3]<<"-"<<a[4]<<a[5]<<a[6]<<a[7]<<a[8]<<"-"<<total%11;
}
