#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
const int N = 1e6 + 7;
struct Edge
{
	int d, u, c;
	bool operator < (const Edge &rhs) const
	{
		return d < rhs.d;
	}
};
vector<Edge> from0, to0;
long long dp[N][2];
long long cost[N];
int main()
{
	ios :: sync_with_stdio(false);
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		from0.clear(), to0.clear();
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < m; i++)
		{
			int d, f, t, c;
			cin >> d >> f >> t >> c;
			if (f == 0)
				from0.push_back({d, t, c});
			else
				to0.push_back({d, f, c});
		}
		sort(from0.begin(), from0.end());
		sort(to0.begin(), to0.end());
		memset(cost, -1, sizeof(cost));
		int l = 0;
		long long temp = 0;
		int sz = 0;
		for (int i = 1; i <= 1e6; i++)
		{
			while (l < to0.size() && to0[l].d == i)
			{
				int u = to0[l].u, c = to0[l].c;
				if (cost[u] == -1)
				{
					sz ++ ;
					cost[u] = c;
					temp += c;
				}
				else if (cost[u] > c)
				{
					temp -= (cost[u] - c);
					cost[u] = c;
				}
				l ++ ;
			}
			if (sz == n)
				dp[i][0] = temp;
		}
		l = from0.size() - 1, sz = 0;
		temp = 0;
		memset(cost, -1, sizeof(cost));
		for (int i = 1e6; i >= 1; i--)
		{
			while (l >= 0 && from0[l].d == i)
			{
				int u = from0[l].u , c = from0[l].c;
				if (cost[u] == -1)
				{
					sz ++;
					cost[u] = c;
					temp += c;
				}
				else if (cost[u] > c)
				{
					temp -= (cost[u] - c);
					cost[u] = c;
				}
				l --;
			}
			if (sz == n)
				dp[i][1] = temp;
		}
		long long ans = -1;
		for (int i = 1; i <= 1e6; i++)
		{
			if (dp[i][0] != -1 && i + k + 1 <= 1e6 && dp[i + k + 1][1] != -1)
			{
				if (ans == -1)
					ans = dp[i][0] + dp[i + k + 1][1];
				else
					ans = min(ans, dp[i][0] + dp[i + k + 1][1]);
			}
		}
		printf("%lld\n", ans);
	}
}