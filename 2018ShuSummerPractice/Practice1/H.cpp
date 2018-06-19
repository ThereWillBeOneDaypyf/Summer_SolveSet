#include<bits/stdc++.h>
using namespace std;

const int N = 505;

char Map[N][N];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int cnt = 0;
        int ret = 0;
        for(int i = 1;i <= n;i ++)
        {
            scanf("%s",Map + i);
            for(int j = 1;j <= m;j ++)
            {
                if(i == 1 || j == 1 || i == n || j == m)
                {
                    if(Map[i][j - 1] == '0')
                        cnt ++;
                }
                else 
                {
                    if(Map[i][j - 1] == '1')
                        ret ++;
                }
            }
        }
        if(ret < cnt)
            printf("-1\n");
        else printf("%d\n",cnt);
    }
}