#include<bits/stdc++.h>
using namespace std;

namespace pro
{
    constexpr int MOD = 1e9 + 7;
    constexpr int N = 1e3 + 7;
    int cnt[N];
    int C[N][N];
    void init()
    {
        C[0][0] = 1;
        for(int i = 1;i <= 1000;i++)
        {
            C[i][0] = 1;
            for(int j = 1;j <= i;j ++)
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= MOD;
            }
        }
        cnt[1] = 1;
        for(int i = 2;i <= 1000;i++)
        {
            cnt[i] = 1;
            decltype(i) temp = i;
            while(temp != 1)
            {
                cnt[i] ++;
                int all = 0;
                for(int j = 0; j <= 30;j++) 
                    if(temp & (1 << j))
                        all ++;
                temp = all;
            }
        }
    }
    long long dp[N][N][3];
    long long dfs(string s,int pos,int ones,int pre,bool status,int k)
    {
        if(pos >= s.length())
            return cnt[ones] == k;
        if(!status && dp[pos][ones][pre] != -1)
            return dp[pos][ones][pre];
        int up = status ? s[pos] - '0' : 1;
        long long ret = 0;
        for(int i = 0;i <= up;i++)
            ret = ret + dfs(s, pos + 1, ones + (i == 1), i,status && (i == up),k) % MOD;
        if(!status)
            dp[pos][ones][pre] = ret;
        return ret;
    }
    void solve()
    {
        string s;
        int k;
        init();
        while(cin >> s >> k)
        {
            if(k == 0)
            {
                cout << 1 << endl;
                continue;
            }
            else if(k == 1)
            {
                cout << static_cast<int>(s.length()) - 1 << endl;
                continue;
            }
            memset(dp, -1, sizeof(dp));
            cout << dfs(s,0,0,0,true,k) << endl;
        }
    }
}

int main()
{
    pro :: solve();
}