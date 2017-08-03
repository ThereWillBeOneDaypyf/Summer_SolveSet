#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...

const int N = 1e6 + 7;

struct Edge
{
	int u, v, next;
	long long d;
} edge[N * 2];

int head[N];
int sz[N];
int tot = 0;
long long ans = 0;
int k;
void init()
{
	memset(head, -1, sizeof(head));
	tot = 0, ans = 0;
}
void add_edge(int u, int v, long long d)
{
	edge[tot] = {u, v, head[u], d};
	head[u] = tot ++;
}
void dfs(int u, int fa)
{
	sz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		long long w = edge[i].d;
		if (v == fa)
			continue;
		dfs(v, u);
		sz[u] += sz[v];
		ans += (long long)(min(sz[v], k) * w);
	}
}
int main()
{
	int n;
	while (scanf("%d%d", &n, &k) == 2)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			long long d;
			scanf("%d%d%lld", &u, &v, &d);
			add_edge(u, v, d);
			add_edge(v, u, d);
		}
		dfs(1, 1);
		printf("%lld\n", ans);
	}
}