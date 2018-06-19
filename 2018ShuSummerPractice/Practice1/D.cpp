#include<bits/stdc++.h>
using namespace std;

const int N = 3e4;

int pre_sum[N][26];
char s[N];

int solve(int p,int n,int id)
{
    if(p == 0)
        return 0;
    int ans = 0;
    int cnt = p / n;
    int ret = p - cnt * n;
    return cnt * pre_sum[n][id] + pre_sum[ret][id];
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        scanf("%s",s + 1);
        memset(pre_sum,0,sizeof(pre_sum));
        for(int i = 1;i <= n;i ++)
        {
            for(int j = 0;j < 26;j ++)
            {
                pre_sum[i][j] = pre_sum[i - 1][j];
            }
            pre_sum[i][s[i] - 'a'] ++;
        }
        for(int i = 0;i < m;i ++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            char op[5];
            scanf("%s",op);
            printf("%d\n",solve(r,n,op[0] - 'a') - solve(l - 1,n,op[0] - 'a'));
        }
        
    }
}