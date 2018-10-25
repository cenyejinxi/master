#include<bits/stdc++.h>
using namespace std;
bool in(int a,int b,int c,int d,int e,int f){
    return a<=b && b<=c && d<=e && e<=f;
}
int main(){
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    ios::sync_with_stdio(false);
    int sp,so,si,su,sl,sk,sj,sh,cnt=0;
    cin>>sp>>so>>si>>su>>sl>>sk>>sj>>sh;
    for(int x=sp;x<=si;x++){
        for(int y=so;y<=su;y++){
            if(not in(sl,x,sj,sk,y,sh)){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

