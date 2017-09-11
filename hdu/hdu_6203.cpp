#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e4 + 8;

struct Node
{
	int u, v, Lca;
};

vector<int> G[N];
vector<Node>Q;
int dep[N], fa[N][21];
int vis[N];
void init()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N; i++)
		G[i].clear();
	Q.clear();
}
void dfs(int u, int Fa, int d)
{
	dep[u] = d, fa[u][0] = Fa;
	for (int i = 1; i <= 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : G[u])
	{
		if (v == Fa)
			continue;
		dfs(v, u, d + 1);
	}
}
int lca(int x, int y)
{
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if (x == y)
		return x;
	for (int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void del(int u)
{
	vis[u] = 1;
	for (auto v : G[u])
	{
		if (v == fa[u][0] || vis[v])
			continue;
		del(v);
	}
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 0; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v), G[v].push_back(u);
		}
		dfs(0, 0, 0);
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			Q.push_back({u, v, lca(u, v)});
		}
		sort(Q.begin(), Q.end(),[](Node a,Node b){return dep[a.Lca] > dep[b.Lca];});
		int ans = 0;
		for (int i = 0; i < Q.size(); i++)
		{
			int u = Q[i].u, v = Q[i].v , Lca = Q[i].Lca;
			if (!vis[u] && !vis[v])
			{
				ans ++;
				del(Lca);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}