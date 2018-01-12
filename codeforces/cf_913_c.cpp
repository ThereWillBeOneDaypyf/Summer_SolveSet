#include<bits/stdc++.h>
using namespace std;

const int N = 100;

long long dp[N][N];
long long c[N];
long long POW[N];
void init()
{
	POW[0] = 1;
	for (int i = 1; i <= 31; i++)
		POW[i] = POW[i - 1] * 2;
}
int main()
{
	int n, m;
	init();
	while (cin >> n >> m)
	{
		int last = 0;
		for (int i = 0; i <= 30; i++)
		{
			if ((m & (1 << i)) != 0)
			{
				last = i;
				break;
			}
		}
		for (int i = 0; i < 100; i ++)
			c[i] = 1e18 + 7;
		for (int i = 0; i < n; i++)
			cin >> c[i];
		for (int i = 30; i >= n; i--)
			for (int j = 0; j < n; j++)
				c[i] = min(c[i], 1LL * c[j] * POW[i - j]);
		for (int i = 0; i <= 30; i++)
		{
			for (int j = 0; j < i; j++)
				c[i] = min(c[i], 1LL * c[j] * POW[i - j]);
			for (int j = i + 1; j <= 30; j++)
				c[i] = min(c[i], c[j]);
		}
		long long ans = 1e18 + 7;
		memset(dp, 0, sizeof(dp));
		for (int i = 30; i > last ; i--)
		{
			if ((m & (1 << i)) != 0)
			{
				if (dp[i + 1][0] != -1)
				{
					long long temp = dp[i + 1][0] + 2LL * c[i];
					ans = min(temp , ans);
					dp[i][1] = temp - c[i];
				}
				else
				{
					dp[i][1] = dp[i + 1][1] + 2LL * c[i];
					ans = min(dp[i][1], ans);
					dp[i][1] -= c[i];
				}
				dp[i][0] = -1;
			}
			else
			{
				if (dp[i + 1][0] != -1)
				{
					ans = min(ans, dp[i + 1][0] + c[i]);
					dp[i][0] = dp[i + 1][0];
				}
				else
				{
					ans = min(ans, dp[i + 1][1] + c[i]);
					dp[i][0] = dp[i + 1][1];
				}
				dp[i][1] = -1;
			}
		}
		if (dp[last + 1][0] != -1)
			ans = min(ans, dp[last + 1][0] + c[last]);
		else
			ans = min(ans, dp[last + 1][1] + c[last]);
		cout << ans << endl;
	}
}
