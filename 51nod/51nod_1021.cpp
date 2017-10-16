#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int sum[1000];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> dp[i][i];
			sum[i] = sum[i - 1] + dp[i][i];
			dp[i][i] = 0;
		}
		for (int i = 2; i <= n; i++)
		{
			for (int l = 1, r = l + i - 1; r <= n; l++, r++)
			{
				dp[l][r] = dp[l][l] + dp[l + 1][r] + sum[r] - sum[l - 1];
				for (int k = l + 1; k < r; k++)
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
			}
		}
		cout << dp[1][n] << endl;
	}
}