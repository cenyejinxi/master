#include <bits/stdc++.h>
using namespace std;

const int MAXN=32005;
int n,m;
int v,p,q;
int m_w[MAXN];    // �����ķ���
int m_c[MAXN];    // �����ļ�ֵ
int f_w[MAXN][3]; // �����ķ���
int f_c[MAXN][3]; // �����ļ�ֵ
int f[MAXN];
int main(){
	// ��Ǯ��n��ϣ��������Ʒ�ĸ���m
    cin >> n >> m;
    for (int i=1;i<=m;i++){
    	// �۸�  ��Ҫ��  
		// q=0����ʾ����ƷΪ���������q>0, ��ʾ����ƷΪ������q�����������ı��
        cin >> v >> p >> q;
        if (q==0){
            m_w[i] = v;
            m_c[i] = v * p;
        }else{
            f_w[q][0]++; // ����q�ĸ�������
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
            // ֻ�������� 
            f[j] = max(f[j], f[j-m_w[i]]+m_c[i]);

            // ѡ����1
            if (j >= m_w[i] + f_w[i][1])
                f[j] = max(f[j], f[ j - m_w[i] - 
					   f_w[i][1] ] + m_c[i] + f_c[i][1]);
            
            // ѡ����2
            if (j >= m_w[i] + f_w[i][2])
                f[j] = max(f[j], f[ j - m_w[i] - 
				       f_w[i][2] ] + m_c[i] + f_c[i][2]);
            
            // ѡ����1�͸���2
            if (j >= m_w[i] + f_w[i][1] + f_w[i][2])
                f[j] = max(f[j], f[ j - m_w[i] - 
				       f_w[i][1] - f_w[i][2] ] + 
					   m_c[i] + f_c[i][1] + f_c[i][2]);

         }
	}

    cout << f[n] << endl;
    return 0;
}
