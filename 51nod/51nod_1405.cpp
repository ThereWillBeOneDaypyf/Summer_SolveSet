#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thasnk to qhl ...

const int N = 1e5 + 7;

vector<int> G[N];
int sz[N];
int n;
long long dp[N];

void dfs(int u, int fa)
{
	sz[u] = 1;
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
		sz[u] += sz[v];
		dp[u] += dp[v] + sz[v];
	}
}
void dfs_(int u, int fa)
{
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		dp[v] = dp[u] - sz[v] + (n - sz[v]);
		dfs_(v, u);
	}
}
int main()
{
	ios :: sync_with_stdio(false);
	while (cin >> n)
	{
		for (int i = 0; i < N; i++)
			G[i].clear();
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 1);
		dfs_(1, 1);
		for (int i = 1; i <= n; i++)
			cout << dp[i] << endl;
	}
}