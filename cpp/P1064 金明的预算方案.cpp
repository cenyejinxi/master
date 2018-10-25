#include <bits/stdc++.h>
using namespace std;

const int MAXN=32005;
int n,m;
int v,p,q;
int m_w[MAXN];    // 主件的费用
int m_c[MAXN];    // 主件的价值
int f_w[MAXN][3]; // 附件的费用
int f_c[MAXN][3]; // 附件的价值
int f[MAXN];
int main(){
	// 总钱数n，希望购买物品的个数m
    cin >> n >> m;
    for (int i=1;i<=m;i++){
    	// 价格  重要度  
		// q=0，表示该物品为主件，如果q>0, 表示该物品为附件，q是所属主件的编号
        cin >> v >> p >> q;
        if (q==0){
            m_w[i] = v;
            m_c[i] = v * p;
        }else{
            f_w[q][0]++; // 主件q的附件数量
            f_w[q][f_w[q][0]] = v;
            f_c[q][f_w[q][0]] = v * p;
        }
    }

    for (int i=1;i<=m;i++)
    {
	    if(m_w[i]==0) {
    		continue;
		} 
    	for (int j=n; j>=m_w[i]; j--){
            // 只考虑主件 
            f[j] = max(f[j], f[j-m_w[i]]+m_c[i]);

            // 选附件1
            if (j >= m_w[i] + f_w[i][1])
                f[j] = max(f[j], f[ j - m_w[i] - 
					   f_w[i][1] ] + m_c[i] + f_c[i][1]);
            
            // 选附件2
            if (j >= m_w[i] + f_w[i][2])
                f[j] = max(f[j], f[ j - m_w[i] - 
				       f_w[i][2] ] + m_c[i] + f_c[i][2]);
            
            // 选附件1和附件2
            if (j >= m_w[i] + f_w[i][1] + f_w[i][2])
                f[j] = max(f[j], f[ j - m_w[i] - 
				       f_w[i][1] - f_w[i][2] ] + 
					   m_c[i] + f_c[i][1] + f_c[i][2]);

         }
	}

    cout << f[n] << endl;
    return 0;
}
