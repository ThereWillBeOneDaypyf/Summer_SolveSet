#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9 +7;

long long dp[120][10005];
int c[N];
int v[N];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,m;
        cin >> n >> m;
        for(int i = 0;i < n;i ++)
            cin >> c[i] >> v[i];
        for(int i = 0;i < 120;i ++)
        {
            for(int j = 10004;j >= 0;j --)
            {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j <= 10000;j ++) 
            {
                if(j < v[i])
                    dp[i + 1][j] = dp[i][j];
                else dp[i + 1][j] = min(dp[i][j],dp[i][j - v[i]]+c[i]);
            }
        }
        long long ans = 0;
        for(int i = 0;i <= 10000;i ++)
        {
            if(dp[n][i] <= m)
                ans = max(ans,(long long)i);
        }
        cout << ans << endl;
    }
}
