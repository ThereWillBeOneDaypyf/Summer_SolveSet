#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 3e5 + 7;
const int MOD = 998244353;
struct Edge
{
	int u, v, d, next;
	int mark;
} edge[N * 4];
int head[N * 2];
int del[N * 2];
int deg[N];
int tot = 0;
void init(int n)
{
	memset(deg, 0, sizeof(deg));
	memset(head, -1, sizeof(head));
	memset(del, 0, sizeof(del));
	memset(edge, 0, sizeof(edge));
	tot = 0;
}
void add_edge(int u, int v, int d)
{
	edge[tot].u = u, edge[tot].v = v, edge[tot].d = d, edge[tot].next = head[u];
	head[u] = tot++;
	edge[tot].v = u, edge[tot].u = v, edge[tot].d = d, edge[tot].next = head[v];
	head[v] = tot++;
}
long long ret[2];
void dfs(int u, int flag)
{
	del[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		int d = edge[i].d;
		if (edge[i].mark)
			continue;
		edge[i].mark = edge[i ^ 1].mark = 1;
		ret[flag] = 1LL * ret[flag] * d % MOD;
		dfs(v, flag ^ 1);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		init(n);
		for (int i = 1; i <= n; i++)
		{
			int v1, d1, v2, d2;
			scanf("%d%d%d%d", &v1, &d1, &v2, &d2);
			add_edge(i, v1 + n, d1);
			add_edge(i, v2 + n, d2);
			deg[v1] ++;
			deg[v2] ++;
		}
		long long ans = 1;
		queue<int>q;
		for (int i = 1; i <= n; i++)
			if (deg[i] == 1)
				q.push(i + n);
		while (!q.empty())
		{
			int v = q.front();
			del[v] = 1;
			q.pop();
			for (int i = head[v]; ~i; i = edge[i].next)
			{
				if (edge[i].mark)
					continue;
				int u = edge[i].v;
				int d = edge[i].d;
				edge[i].mark = edge[i ^ 1].mark = 1;
				del[u] = 1;
				ans = ans % MOD * d % MOD;
				ans %= MOD;
				for (int j = head[u]; ~j; j = edge[j].next)
				{
					if (edge[j].mark)
						continue;
					int vv = edge[j].v;
					edge[j].mark = edge[j ^ 1].mark = 1;
					deg[vv - n] --;
					if (deg[vv - n] == 1)
						q.push(vv);
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!del[i])
			{
				ret[0] = ret[1] = 1;
				dfs(i, 0);
				ans = ans * 1LL * (ret[0] % MOD + ret[1] % MOD) % MOD;
				ans %= MOD;
			}
		}
		printf("%lld\n", ans);
	}
}