#include<bits/stdc++.h>
using namespace std;
int in(int a,int b,int c,int d,int e,int f){
	if(c<=a && a<e && d<=b && b<f){
		return 1;
	}
	return 0;
}
int main(){
	freopen("billboard.in","r",stdin);
	freopen("billboard.out","w",stdout);
	int sl,sk,sj,sh,sp,so,si,su,sm,sn,sb,sv,cnt=0;
	cin>>sl>>sk>>sj>>sh>>sp>>so>>si>>su>>sm>>sn>>sb>>sv;
	int lowx=min(sl,sp),lowy=min(sk,so),highx=max(sj,si),highy=max(sh,su);
	for(int x=lowx;x<=highx;x++){
		for(int y=lowy;y<=highy;y++){
			if((in(x,y,sl,sk,sj,sh)==1 || in(x,y,sp,so,si,su)==1) && in(x,y,sm,sn,sb,sv)==0 ){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
