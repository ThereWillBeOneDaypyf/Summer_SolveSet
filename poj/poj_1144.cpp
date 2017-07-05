#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e5 + 5;

struct Edge
{
	int u, v;
	int next;
} edge[N * 2];

int head[N], dfn[N], low[N];
int ans[N];
int tot = 0;
int Index = 0;
int son, FA;
int n;
void init()
{
	memset(head, -1, sizeof(head));
	memset(ans, 0, sizeof(ans));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	tot = 0;
	Index = 0;
}
void add_edge(int u, int v)
{
	edge[tot].u = u, edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++Index;
	for (int i = head[u]; i != -1 ; i = edge[i].next)
	{
		int v = edge[i].v;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u] && u != FA)
				ans[u] ++;
			else if (u == FA)
				son ++;
		}
		else low[u] = min(low[u], dfn[v]);
	}
}
void solve()
{
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			FA = i;
			son = 0;
			tarjan(i);
			if (son <= 1)
				ans[i] = 0;
			else
				ans[i] = son - 1;
		}
	}
}
int main()
{
	while (cin >> n && n)
	{
		init();
		int u;
		while (cin >> u && u)
		{
			char x;
			int v;
			while (scanf("%d%c", &v, &x) == 2)
			{
				add_edge(u, v);
				add_edge(v, u);
				if (x == '\n')
					break;
			}
		}
		solve();
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (ans[i])
				cnt ++;
		cout << cnt << endl;
	}
	return 0;
}