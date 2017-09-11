#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
const int N = 1e5 + 7;
int val[N];
int dp[N][2];
vector<pair<int, int> > G[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
}
void add_edge(int u, int v, int d)
{
	G[u].push_back(make_pair(v, d));
}
void dfs(int u, int fa)
{
	dp[u][0] = val[u];
	dp[u][1] = -val[u];
	for (auto temp : G[u])
	{
		int v = temp.first, d = temp.second;
		if (v == fa)
			continue;
		dfs(v, u);
		dp[u][0] = max(dp[u][0], dp[v][0] - d);
		dp[u][1] = max(dp[u][1], dp[v][1] - d);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", val + i);
		for (int i = 1; i < n; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d), add_edge(v, u, d);
		}
		int ans = 0;
		dfs(1, 1);
		for (int i = 1; i <= n; i++)
			ans = max(ans, dp[i][0] + dp[i][1]);
		printf("%d\n", ans);
	}
}