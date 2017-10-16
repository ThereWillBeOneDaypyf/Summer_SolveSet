#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

vector<pair<int, int> > G[N];
int sz[N];
long long ans = 0;
int n;
int root = 0;
int Max = N;
long long dis[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
	memset(dis, 0, sizeof(dis));
	ans = 0;
	root = 0;
	Max = N;
}
void add_edge(int u, int v, int d)
{
	G[u].push_back(make_pair(v, d));
	G[v].push_back(make_pair(u, d));
}
void dfs_root(int u, int fa)
{
	sz[u] = 1;
	for (auto temp : G[u])
	{
		int v = temp.first;
		if (temp.first == fa)
			continue;
		dfs_root(temp.first, u);
		sz[u] += sz[v];
	}
	int res = 0;
	for (auto temp : G[u])
	{
		int v = temp.first;
		if (temp.first == fa)
			continue;
		res = max(res, sz[v]);
	}
	res = max(res, n - sz[u]);
	if (res < Max)
		Max = res , root = u;
}
void dfs(int u, int fa, long long d)
{
	dis[u] = d;
	for (auto temp : G[u])
	{
		int v = temp.first;
		int w = temp.second;
		if (v == fa)
			continue;
		dfs(v, u, d + w);
	}
}
int main()
{
	ios :: sync_with_stdio(false);
	while (cin >> n)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			add_edge(u, v, d);
		}
		dfs_root(1, 1);
		dfs(root, root, 0);
		for (int i = 1; i <= n; i++)
			ans += dis[i];
		cout << ans << endl;
	}
}