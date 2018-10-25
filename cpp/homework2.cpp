#include<bits/stdc++.h>
using namespace std;
int adx64heap[101],odx008heap[101],orgd0xfheap[101];
int main()
{
	freopen("shuffle.in","r",stdin);
	freopen("shuffle.out","w",stdout); 
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) 
	    cin>>adx64heap[i];
	for (int i=1; i<=n; i++) 
	    cin>>odx008heap[i];
	for (int i=0;i<3;i++){
	    for (int j=1;j<=n;j++){
			orgd0xfheap[j]=odx008heap[adx64heap[j]];
		}
	    for (int j=1;j<=n;j++){
			odx008heap[j]=orgd0xfheap[j];
		}
	}
	for (int i=1;i<=n;i++){
	    cout<<odx008heap[i]<<endl;
	}
	return 0;
}
