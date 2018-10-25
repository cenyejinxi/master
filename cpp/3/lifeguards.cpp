#include<bits/stdc++.h>
using namespace std;
struct e{
    int s,e;
}s[100];
int a[1000];
int main(){
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    int n,t1,t2,cnt,l=INT_MIN;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t1>>t2;
        s[i].s=t1;s[i].e=t2;
    }
    for(int i=0;i<n;i++){
        for(int j=s[i].s;j<=s[i].e;j++){
            a[j]++;
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=s[i].s;j<=s[i].e;j++){
            a[j]--;
        }
        cnt=0;
        for(int i=0;i<1000;i++){
            if(a[i]>0){
                cnt++;
            }
        }
        l=max(l,cnt);
        for(int j=s[i].s;j<=s[i].e;j++){
            a[j]++;
        }
    }
    cout<<l;
    return 0;
}
