#include <bits/stdc++.h>
using namespace std;

const int N = 200;

double dp[N][N];
double Map[N][N];

int main()
{
    ios ::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int sum = pow(2, n);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < sum; i++)
            dp[0][i] = 1.0;
        for (int i = 0; i < sum; i++)
            for (int j = 0; j < sum; j++)
                cin >> Map[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < sum; j++)
            {
                for (int k = 0; k < sum; k++)
                {
                    if (((j >> (i - 1)) ^ (k >> (i - 1))) != 1)
                        continue;
                    //cout << (j >> (i - 1)) << " " << (k >> (i - 1)) << endl;
                    dp[i][j] += dp[i - 1][j] * dp[i - 1][k] * Map[j][k];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < sum; i++)
            //    cout << dp[n][i] << endl;
            if (dp[n][ans] < dp[n][i])
                ans = i;
        cout << ans + 1 << endl;
    }
}