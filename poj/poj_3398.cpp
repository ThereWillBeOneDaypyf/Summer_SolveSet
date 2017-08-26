#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Edge
{
	int u, v, next;
} edge[N * 2];
int head[N];
long long dp[N][3];
int tot = 0;
void init()
{
	memset(head, -1, sizeof(head));
	tot = 0;
}
void add_edge(int u, int v)
{
	edge[tot] = {u, v, head[u]};
	head[u] = tot ++;
}
void tree_up(int u, int fa)
{
	dp[u][0] = 1, dp[u][1] = 0, dp[u][2] = 0x3f3f3f3f;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		tree_up(v, u);
		dp[u][0] += min(dp[v][1], dp[v][0]);
		dp[u][1] += dp[v][2];
	}
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		dp[u][2] = min(dp[u][2], dp[u][1] - dp[v][2] + dp[v][0]);
	}
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
			continue;
		if (n == -1)
			break;
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		tree_up(1, 1);
		printf("%lld\n", min(dp[1][0], dp[1][2]));
	}
}