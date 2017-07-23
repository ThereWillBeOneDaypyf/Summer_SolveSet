#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 2e5 + 7;

struct Edge
{
	int u, v, d, next;
} edge[N * 2];

int Mx[N], sz[N], vis[N];
int head[N];
int root, Min;
int n, k;
vector<int>dis;
int tot = 0, ans = 0;

void init()
{
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	tot = ans = 0;
}
void add_edge(int u, int v, int d)
{
	edge[tot].u = u, edge[tot].v = v, edge[tot].d = d;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void dfs_sz(int u, int fa)
{
	sz[u] = 1;
	Mx[u] = 0;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa || vis[v])
			continue;
		dfs_sz(v, u);
		sz[u] += sz[v];
		Mx[u] = max(Mx[u], sz[v]);
	}
}
void dfs_root(int r, int u, int fa)
{
	Mx[u] = max(Mx[u] , sz[r] - sz[u]);
	if (Mx[u] < Min)
		root = u, Min = Mx[u];
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa || vis[v])
			continue;
		dfs_root(r, v, u);
	}
}
void get_dis(int u, int fa, int d)
{
	dis.push_back(d);
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		int w = edge[i].d;
		if (v == fa || vis[v])
			continue;
		get_dis(v, u, d + w);
	}
}
int get_ans(int u, int d)
{
	dis.clear();
	get_dis(u, 0, d);
	sort(dis.begin(), dis.end());
	int i = 0, j = dis.size() - 1;
	int res = 0;
	while (i < j)
	{
		while (dis[i] + dis[j] > k && i < j)
			j--;
		res += j - i;
		i ++;
	}
	return res;
}
void dfs(int u)
{
	Min = n;
	dfs_sz(u, 0);
	dfs_root(u, u, 0);
	ans += get_ans(root, 0);
	vis[root] = 1;
	for (int i = head[root]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (vis[v])
			continue;
		ans -= get_ans(v, edge[i].d);
		dfs(v);
	}
}
int main()
{
	while (scanf("%d%d", &n, &k) == 2)
	{
		if (n == 0 && k == 0)
			break;
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d);
			add_edge(v, u, d);
		}
		dfs(1);
		printf("%d\n", ans);
	}
}