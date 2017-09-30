#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int>G[N];
set<int>s[2];
void init()
{
	for (int i = 0 ; i < N; i++)
		G[i].clear();
	s[0].clear(), s[1].clear();
}
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
void dfs(int u, int fa, int flag)
{
	s[flag].insert(u);
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u, flag ^ 1);
	}
}
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			add_edge(u, v);
		}
		dfs(1, 1, 0);
		long long ans = 1LL * s[0].size() * s[1].size();
		ans -= (n - 1);
		cout << ans << endl;
	}
}