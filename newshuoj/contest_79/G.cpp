#include<bits/stdc++.h>
using namespace std;

const int N = 1e7;

int dp[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int w[2], t[2];
			cin >> w[0] >> t[0] >> w[1] >> t[1];
			for (int j = m; j >= 0; j--)
			{
				for (int k = 0; k < 2; k++)
				{
					if (j >= t[k])
						dp[j] = max(dp[j], dp[j - t[k]] + w[k]);
				}
			}
		}
		//cout << ans << endl;
		cout << dp[m] << endl;
	}
}
