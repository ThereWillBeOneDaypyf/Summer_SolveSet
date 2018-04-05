#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;

int dp[N][11][2];
struct Node
{
    int id;
    int cnt;
};

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        string s;
        cin >> s;
        memset(dp, 0, sizeof(dp));
        int beg = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                beg = i;
                break;
            }
        }
        if (beg == -1)
        {
            cout << 0 << endl;
            continue;
        }
        dp[beg][0][(s[beg] - 'a') ^ 1] = -INF, dp[beg][0][(s[beg] - 'a')] = 1;
        for (int i = beg + 1; i < s.size(); i++)
        {
            int cur_id = s[i] - 'a';
            int val = 1;
            for (int j = 0; j <= m; j++)
            {
                dp[i][j][cur_id] = dp[i - 1][j][cur_id] + val;
                if (j)
                    dp[i][j][cur_id] = max(dp[i][j][cur_id], dp[i - 1][j - 1][cur_id ^ 1] + val);
                dp[i][j][cur_id ^ 1] = dp[i - 1][j][cur_id ^ 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j <= m; j++)
                for (int k = 0; k < 2; k++)
                    ans = max(ans, dp[i][j][k]);
        cout << ans << endl;
    }
}