#include <bits/stdc++.h>
using namespace std;

#define INF  0x3f3f3f3f
int Map[50][50];
int ans = 1e9;
int dp[1 << 16][20];
int main()
{
    int n;
    int ka = 0;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &Map[i][j]);
                if (Map[i][j] == -1)
                    Map[i][j] = INF;
            }
        }
        memset(dp, INF, sizeof(dp));
        dp[1][0] = 0;
        for (int i = 0; i < (1 << n); i++) // {i} v j ,
        {
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (j == k)
                            continue;
                        if (i & (1 << k))
                            dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + Map[k][j]);
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; i++)
            ans = min(dp[(1 << n) - 1][i] + Map[i][0], ans);
        printf("Case %d\n", ++ ka);
        if (ans >= INF)
            printf("No loop\n");
        else printf("%d\n", ans);
    }
}