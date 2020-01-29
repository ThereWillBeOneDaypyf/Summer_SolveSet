#include <bits/stdc++.h>

using namespace std;

long long dp[44][44][44][44];
int a[1000];
int b[200];
int cnt[5];

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        for(int j = 0; j < m; j ++)
            cin >> b[j], cnt[b[j]] ++;
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= cnt[1]; i ++)
        {
            for(int j = 0; j <= cnt[2]; j ++)
            {
                for(int k = 0; k <= cnt[3]; k ++)
                {
                    for(int x = 0; x <= cnt[4]; x ++)
                    {
                        if(i)
                            dp[i][j][k][x] = max(dp[i][j][k][x], dp[i - 1][j][k][x]);
                        if(j)
                            dp[i][j][k][x] = max(dp[i][j][k][x], dp[i][j - 1][k][x]);
                        if(k)
                            dp[i][j][k][x] = max(dp[i][j][k][x], dp[i][j][k - 1][x]);
                        if(x)
                            dp[i][j][k][x] = max(dp[i][j][k][x], dp[i][j][k][x - 1]);
                        dp[i][j][k][x] += a[i + j * 2 + k * 3 + x * 4];
                    }
                }
            }
        }
        cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
    }
}