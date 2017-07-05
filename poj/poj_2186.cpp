#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;

const int N = 1e5;

int dfn[N], low[N], belong[N];
int instack[N];
int deg[N];
int head[N];
stack<int>st;
int tot = 0;
int block = 0;
int Index = 0;
int n;

struct Edge
{
	int u, v;
	int next;
} edge[N * 2];

void init()
{
	tot = block = Index = 0;
	memset(head, -1, sizeof(head));
	memset(instack, 0, sizeof(instack));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(belong, 0, sizeof(belong));
	memset(deg, 0, sizeof(deg));
	while (!st.empty())
		st.pop();
}
void add_edge(int u, int v)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++ Index;
	instack[u] = 1;
	st.push(u);
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (instack[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		int x;
		block ++;
		do
		{
			x = st.top();
			belong[x] = block;
			instack[x] = 0;
			st.pop();
		}
		while (x != u);
	}
}
void solve()
{
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
}
int main()
{
	int m;
	while (cin >> n >> m)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			add_edge(u, v);
		}
		solve();
		for (int i = 0; i < tot; i++)
		{
			int u = edge[i].u , v = edge[i].v;
			if (belong[u] != belong[v])
				deg[belong[u]] ++;
		}
		int ans = 0;
		int tar ;
		for (int i = 1; i <= block; i++)
			if (!deg[i])
			{
				ans ++;
				tar = i;
			}
		if (ans != 1)
			cout << 0 << endl;
		else
		{
			int cnt = 0 ;
			for (int i = 1; i <= n; i++)
				if (belong[i] == tar)
					cnt ++;
			cout << cnt << endl;
		}
	}
}