#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int a[] = {1, 5, 10, 20, 50, 100};
long long c[11];
long long dp[N];

void init(int k, int p)
{
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= k; i++)
    {
        long long cnt = 0;
        long long temp = 1LL * i * p;
        for (int j = 5; j >= 0; j--)
        {
            cnt += temp / a[j];
            temp %= a[j];
        }
        c[i] = cnt;
    }
}
int k;

int main()
{
    int n, p;
    while (cin >> n >> k >> p)
    {
        init(k, p);
        long long res = 1e18 + 7;
        long long temp = n;
        for (int cur = 1; cur <= k; cur++)
        {
            n = temp;
            for (int i = 0; i < N; i++)
                dp[i] = 1e18 + 7;
            long long ans = 0;
            if (n > 3000)
            {
                ans += 1LL * (n - 3000) / cur * c[cur];
                n = 3000 + (n - 3000) % cur;
            }
            dp[0] = 0;
            for (int i = 1; i <= k; i++)
                for (int j = i; j <= n; j++)
                    dp[j] = min(dp[j], dp[j - i] + c[i]);
            res = min(res , ans + dp[n]);
        }
        cout <<res << endl;
    }
}