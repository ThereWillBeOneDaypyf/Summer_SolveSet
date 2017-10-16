#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;

vector<int>G[N];
vector<pair<int, int> >vG[N];
int dis[N];
int fa[N][21];
int dfn[N], L[N], R[N];
int tot = 0;
int st[N];
int rt, Max;
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
void add_vedge(int u, int v, int d)
{
	vG[u].push_back(make_pair(v, d));
	vG[v].push_back(make_pair(u, d));
}
void dfs(int u, int Fa, int d)
{
	dfn[u] = L[u] = ++ tot;
	dis[u] = d;
	fa[u][0] = Fa;
	for (int i = 1; i <= 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (auto v : G[u])
	{
		if (v == Fa)
			continue;
		dfs(v, u, d + 1);
	}
	R[u] = tot;
}
int lca(int u, int v)
{
	if (dis[u] < dis[v])
		swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dis[fa[u][i]] >= dis[v])
			u = fa[u][i];
	if (u == v)
		return u;
	for (int i = 20; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
bool check(int u, int v)
{
	if (L[u] <= L[v] && R[v] <= R[u])
		return true;
	return false;
}
void dfs_root(int u, int Fa, int d, int del)
{
	if (!del && d >= Max)
	{
		rt = u;
		Max = d;
	}
	Max = max(Max, d);
	for (auto temp : vG[u])
	{
		int v = temp.first;
		int w = temp.second;
		if (v == Fa)
			continue;
		dfs_root(v, u, d + w, del);
	}
	if (del)
		vG[u].clear();
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < N; i++)
		{
			G[i].clear();
			vG[i].clear();
		}
		tot = 0;
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
		}
		dfs(1, 1, 0);
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int cnt;
			scanf("%d", &cnt);
			vector<int> p;
			p.clear();
			for (int j = 0; j < cnt; j++)
			{
				int x;
				scanf("%d", &x);
				p.push_back(x);
			}
			int num = p.size();
			sort(p.begin(), p.end(), [](int a, int b) {return dfn[a] < dfn[b];});
			for (int j = 1; j < num; j++)
				p.push_back(lca(p[j], p[j - 1]));
			sort(p.begin(), p.end(), [](int a, int b) {return dfn[a] < dfn[b];});
			p.erase(unique(p.begin(), p.end()), p.end());
			int top = 0;
			int root = 0;
			for (int j = 0; j < p.size(); j++)
			{
				while (top && !check(st[top], p[j]))
					top --;
				if (!top)
				{
					st[++top] = p[j];
					root = p[j];
				}
				else
				{
					st[++top] = p[j];
					add_vedge(st[top - 1], st[top], -dis[st[top - 1]] + dis[st[top]]);
				}
			}
			Max = -1;
			dfs_root(root, root, 0, 0);
			dfs_root(rt, rt, 0, 1);
			printf("%d\n", (Max + 1) / 2);
		}
	}
}