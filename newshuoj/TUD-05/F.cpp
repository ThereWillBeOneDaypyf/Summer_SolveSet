#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3 + 8;

long long Map[N][N];
long long dp[N][N];
int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> Map[i][j];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				dp[i][j] = max(dp[i][j - 1], max(dp[i - 1][j], dp[i - 1][j - 1])) + Map[i][j];
			}
		}
		cout << "Scenario #" << ++ ka << ":" << endl;
		cout << dp[n][m] << endl;
		cout << endl;
	}
}