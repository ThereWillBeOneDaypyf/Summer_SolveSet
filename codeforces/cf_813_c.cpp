#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 2e5 + 8;

struct Edge
{
	int u, v, next;
} edge[N * 2];
int head[N];
int tot = 0;
int dis_a[N], dis_b[N];
int deg[N];
void init()
{
	memset(head, -1, sizeof(head));
	memset(deg, 0, sizeof(deg));
	tot = 0;
}
void add_edge(int u, int v)
{
	edge[tot] = {u, v, head[u]};
	head[u] = tot ++;
}
void dfs_alice(int u, int fa, int d)
{
	dis_a[u] = d;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		dfs_alice(v, u, d + 1);
	}
}
void dfs_bob(int u, int fa, int d)
{
	dis_b[u] = d;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		dfs_bob(v, u, d + 1);
	}
}
int main()
{
	int n, x;
	while (cin >> n >> x)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			add_edge(u, v);
			add_edge(v, u);
			deg[u] ++, deg[v]++;
		}
		dfs_alice(1, 0, 0);
		dfs_bob(x, 0, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 1)
				if (dis_a[i] > dis_b[i])
					ans = max(ans, dis_a[i] * 2);
		}
		cout << ans << endl;
	}
}