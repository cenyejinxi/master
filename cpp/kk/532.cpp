#include<bits/stdc++.h>
using namespace std;
char m[1000][1000];
int n,e;
int dis[10][10][2],pa[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y,int step,bool life){
	if(dis[x][y][life]<step){
		return;
	}
	dis[x][y][life]=step;
	for(int i=0;i<4;i++){
		int tx=x+pa[i][0],ty=y+pa[i][1];
		if(m[tx][ty]=='o' && tx>=1 && tx<=n && ty>=1 && ty<=e){
			dfs(tx,ty,step+1,life);
		}
		else if(m[tx][ty]=='#' && life && tx>=1 && tx<=n && ty>=1 && ty<=e){
			dfs(tx,ty,step+1,false);
		}
	}
}
int main(){
	cin>>n>>e;
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<n;i++){
		for(int j=0;j<e;j++){
			cin>>m[i][j];
		}
	}
	dfs(0,0,0,1);
	cout<<min(dis[e][n][0],dis[e][n][1]);
	return 0;
}
