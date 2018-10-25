/*#include<iostream>
#include<cmath>
using namespace std;
int opt_in[22][22][22];
void w(int a,int b,int c){
	if(a==0 || b==0 || c==0){
		opt_in[a][b][c]=1;
		return;
	}
	if(a==21 || b==21 || c==21){
		opt_in[a][b][c]=opt_in[20][20][20];
		return;
	}
	if(a < b < c){
		opt_in[a][b][c]=opt_in[a][b][c-1]+opt_in[a][b-1][c-1]-opt_in[a][b-1][c];
		return;
	}
	opt_in[a][b][c]=opt_in[a-1][b][c]+opt_in[a-1][b-1][c]+opt_in[a-1][b][c-1]-opt_in[a-1][b-1][c-a];
	return;
}
int main(){
	for(int i=0;i<=21;i++){
		for(int j=0;j<=21;j++){
			for(int k=0;k<=21;k++){
				w(i,j,k);
			}
		}
	}
	cout<<opt_in[20][20][20];
	int i,j,k;
	cin>>i>>j>>k;
	i=min(21,i);
	j=min(21,j);
	k=min(21,k);
	i=max(0,i);
	j=max(0,j);
	k=max(0,k);
	cout<<opt_in[i][j][k];
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rpt[25][25][25];
ll w(ll a,ll b,ll c)
{
    if(a<=0||b<=0||c<=0) return 1;
    else if(rpt[a][b][c]!=0) return rpt[a][b][c];
    else if(a>20||b>20||c>20) rpt[a][b][c]=w(20,20,20);
    else if(a<b&&b<c) rpt[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    else rpt[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return rpt[a][b][c];
}
int main()
{
    ll a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3){
        memset(rpt,0,sizeof(rpt));
        if(a==-1&&b==-1&&c==-1) break;
        printf("w(%lld, %lld, %lld) = ",a,b,c);
        if(a>20) a=21;
        if(b>20) b=21;
        if(c>20) c=21;
        printf("%lld\n",w(a,b,c));
    }
    return 0;
}
