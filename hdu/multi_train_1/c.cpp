#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5 + 7;

struct Edge
{
	int u, v, next;
} edge[N * 2];

int head[N];
int c[N];
int sz[N], sum[N];
int vis[N];
int tot = 0;
long long ans = 0;
void init()
{
	ans = 0;
	memset(head, -1, sizeof(head));
	memset(sum, 0, sizeof(sum));
	memset(vis, 0, sizeof(vis));
	tot = 0;
}
void add_edge(int u, int v)
{
	edge[tot] = {u, v, head[u]};
	head[u] = tot ++;
}
void dfs(int u, int fa)
{
	sz[u] = 1;
	sum[c[u]] ++;
	long long pre = sum[c[u]];
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		dfs(v, u);
		sz[u] += sz[v];
		long long ct = sz[v] - sum[c[u]] + pre;
		ans += 1LL * ct * (ct - 1) / 2;
		sum[c[u]] += ct;
		pre = sum[c[u]];
	}
}
int main()
{
	int ka = 0;
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", c + i);
			if (!vis[c[i]])
			{
				vis[c[i]] = 1;
				cnt ++;
			}
		}
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs(1, 1);
		long long res = 1LL * cnt * n * (n - 1) / 2 - ans;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
			{
				long long ct = n - sum[i];
				res -= (long long)(ct - 1) * ct / 2;
			}
		}
		printf("Case #%d: %lld\n", ++ka , res);
	}
	return 0;
}