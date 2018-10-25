#include<bits/stdc++.h>
using namespace std;
int main(){
    char a;
    bool k=false;
    while(scanf("%c",&a)!=0){
        if(a!='/'){
            k=false;
            printf("%c",a);
        }
        else{
            if(k){
                continue;
            }
            else{
                printf("%c",a);
                k=true;
            }
        }
    }
    return 0;
}
