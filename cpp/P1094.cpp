#include<bits/stdc++.h>
using namespace std;
int a[1000000],ans;
int main(){
    int n,w;
	cin>>w>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int z=0,y=n-1;
    while(z<=y){
        if(a[z]+a[y]<=w){
			ans++;z++;y--;
		}
        else{
			y--;ans++;
		}
    }
    cout<<ans<<endl;
    return 0;
}
