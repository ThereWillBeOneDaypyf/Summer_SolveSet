#include<bits/stdc++.h>
using namespace std;
class Solution {
    int N = 1e6 + 1;
    long long dp[1000001][2];
    int MOD = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= steps; i ++)
        {
            for(int j = 0; j < arrLen; j ++)
            {
                dp[j][i % 2] = dp[j][(i + 1) % 2] % MOD;
                if(j != 0)
                    dp[j][i % 2] += dp[j - 1][(i + 1) % 2] % MOD;
                if(j != arrLen)
                    dp[j][i % 2] += dp[j + 1][(i + 1) % 2] % MOD;
                if(dp[j][i % 2] == 0)
                    break;
            }
        }
        return dp[0][steps % 2] % MOD;
    }
};