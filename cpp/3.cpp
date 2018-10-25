#include<cmath>
#include<stdlib.h>
#include<cstring>
#include<iostream>
using namespace std;
int a[101][3];double f[101][101];
int n,i,j,k,x,y,m,s,e;
int main(){
    //freopen("short.in","r",stdin);
    freopen("short.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];}
    cin>>m;
    memset(f,0x7f,sizeof(f));
    for (i=1;i<=m;i++){
        cin>>x>>y;
        f[y][x]=f[x][y]=sqrt(pow(double(a[x][1]-a[y][1]),2)+pow(double(a[x][2]-a[y][2]),2));
    }
    cin>>s>>e;
    for (k=1;k<=n;k++){
        for (i=1;i<=n;i++){
            for (j=1;j<=n;j++){
                if ((i-j)*(j-k)*(k-i)&& f[i][k]+f[k][j]<f[i][j])
                f[i][j]=f[i][k]+f[k][j];
    }}}
    printf("%.2lf\n",f[s][e]);
}
