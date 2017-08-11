#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
int dp[500][5000];
int v[5] = {50, 25, 10, 5, 1};
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i < 5; i++)
		{
			for (int k = 1; k <= 100; k++)
				for (int j = n; j >= v[i]; j--)
				{
					if (dp[k - 1][j - v[i]] != -1)
					{
						if (dp[k][j] == -1)
							dp[k][j] = dp[k - 1][j - v[i]];
						else
							dp[k][j] += dp[k - 1][j - v[i]];
					}
				}
		}
		long long ans = 0;
		for (int i = 0; i <= 100; i++)
			ans += dp[i][n];
		cout << ans << endl;
	}
}