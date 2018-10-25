#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;  // n表示顶点数  m表示边数 
	cin>>n>>m;
	
	int e[n+1][n+1];
	memset(e, 0x3f, sizeof(e));
	
	for(int i=1; i<=n; i++)
		e[i][i]=0;
	
	// 读入两点之间的距离 
	int t1, t2, t3;
	for(int i=1; i<=m; i++)
	{
		cin>>t1>>t2>>t3;
		e[t1][t2]=t3;
	}
		
	int dis[n+1];
	for(int i=1; i<=n; i++)
	{
		dis[i]=e[1][i];
	}
	
	bool book[n+1]={};
	book[1]=true;
	
    // Dijkstra
    for(int i=1; i<=n-1; i++)
    {
    	// 寻找距离源点最短的点u
    	int minx=INT_MAX,u;
    	for(int j=2;j<=n;j++){
    		if(dis[j]<minx&&!book[j]){
				minx=dis[j];
				u=j;
			}
		} 

		
		// 以u为出发点，对所有的边进行松弛 
        book[u]=true;
        for(int j=1;j<=n;j++){
        	if(e[u][j]<0x3f3f3f3f){
        		if(dis[j]>dis[u]+e[u][j]){
        			dis[j]=dis[u]+e[u][j];
				}
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		cout<<dis[i]<<" ";
	}	
		
	
    return 0; 
}
