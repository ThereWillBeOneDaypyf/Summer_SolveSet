#include<bits/stdc++.h>
using namespace std;

int n, k;
long long dp[100][2];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		dp[1][0] = 1, dp[1][1] = 1;
		for (int i = 2; i < 50; i++)
		{
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][1] = dp[i - 1][0];
		}
		string s = "";
		if (k > dp[n][0] + dp[n][1])
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = n; i >= 1; i--)
		{
			if (dp[i][0] < k)
			{
				k -= dp[i][0];
				s += "1";
			}
			else
			{
				s += "0";
			}
		}
		cout << s << endl;
	}
}