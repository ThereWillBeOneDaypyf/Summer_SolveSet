#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
const int K = 11;
const int MOD = 998244353;

long long t[N][K];
long long dp[N][K];

void init()
{
    memset(t, 0, sizeof(t));
    memset(dp, 0, sizeof(dp));
}

int lowbit(int x)
{
    return x & (-x);
}

void add(int pos, int k, int x) 
{
    while(pos < N) 
    {
        t[pos][k] += x;
        t[pos][k] %= MOD;
        pos += lowbit(pos);
    }
}

int query(int pos, int k)
{
    long long ans = 0;
    while(pos > 0)
    {
       ans += t[pos][k]; 
       ans %= MOD;
       pos -= lowbit(pos);
    }
    return ans;
}

vector<int> b;

void solve()
{
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
}

int getPos(int val)
{
    return lower_bound(b.begin(), b.end(), val) - b.begin() + 1;
}

int main()
{
    int n, k;
    while(cin >> n >> k)
    {
        init();
        b.clear();
        vector<int> v(n);
        for(int i = 0; i < n; i ++)
        {
            cin >> v[i];
            b.push_back(v[i]);
        }
        solve();
        dp[0][0] = 0;
        dp[0][1] = 1;
        add(getPos(v[0]), 1, 1);
        for(int i = 1; i < n; i ++)
        {
            for(int j = k; j >= 1; j --)
            {
                int pos = getPos(v[i]);
                dp[i][j] = query(pos - 1, j - 1);
                if(j == 1)
                    dp[i][j] ++;
                // cout << pos << " " << j << " " << query(pos - 1, j - 1) << " " << dp[i][j] << endl;
                add(pos, j, dp[i][j]);
            }
        }
        long long ans = 0;
        for(int j = 0; j < n; j++)
        {
            ans += dp[j][k];
            // cout << dp[j][k] << " ";
            ans %= MOD;
        }
        // cout << endl;
        cout << ans << endl;
    }
}