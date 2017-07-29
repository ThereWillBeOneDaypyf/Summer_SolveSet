#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 8;

struct Edge
{
	int u, v;
	int next;
} edge[N * 2];

int head[N];
int val[N], vis[N];
int sum[N];
int n, tot = 0;
int all = 0;
int ok1 = 0, ok2 = 0;
pair<int, int>x;
void init()
{
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
	tot = 0;
	ok1 = ok2 = 0;
}
void add_edge(int u, int v)
{
	edge[tot] = {u, v, head[u]};
	head[u] = tot ++;
}
void dfs(int u , int fa)
{
	sum[u] = val[u];
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		dfs(v, u);
		sum[u] += sum[v];
	}
	if (!ok1 && sum[u] == all / 3)
		ok1 = 1, x.first = u, vis[u] = 1;
	return;
}
void dfs_ans(int u, int fa)
{
	sum[u] = val[u];
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa || vis[v])
			continue;
		dfs_ans(v, u);
		sum[u] += sum[v];
	}
	if (!ok2 && sum[u] == all / 3)
		ok2 = 1, x.second = u;
	return;
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		int root = 0;
		for (int i = 1 ; i <= n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &val[i]);
			add_edge(u, i);
			add_edge(i, u);
			all += val[i];
			if (u == 0)
				root = i;
		}
		if (all % 3)
		{
			printf("-1\n");
			continue;
		}
		memset(sum, 0, sizeof(sum));
		dfs(0, 0);
		if (!ok1)
		{
			printf("-1\n");
			continue;
		}
		memset(sum, 0, sizeof(sum));
		dfs_ans(0, 0);
		if (!ok2)
		{
			printf("-1\n");
			continue;
		}
		if (x.first == root || x.second == root)
		{
			printf("-1\n");
			continue;
		}
		printf("%d %d\n", x.first, x.second);
	}
}