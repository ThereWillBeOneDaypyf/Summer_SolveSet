#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5 + 7;

struct Edge
{
	int u, v , next;
	int d;
} edge[N * 2];
struct Tire
{
	int next[2];
} t[N * 32];
int head[N], tot = 0;
int cnt = 0;
int dis[N], a[N];
void NewNode(int r)
{
	for (int i = 0; i < 2; i++)
		t[r].next[i] = 0;
}
void NewTree()
{
	cnt = 0;
	NewNode(0);
}
void init()
{
	memset(head, -1, sizeof(head));
	tot = 0;
	NewTree();
}
void add_edge(int u, int v, int d)
{
	edge[tot].u = u, edge[tot].v = v, edge[tot].d = d, edge[tot].next = head[u];
	head[u] = tot ++;
}
void insert(int x)
{
	int r = 0;
	for (int i = 31; i >= 0; i--)
	{
		int val = (x & (1 << i));
		val == 0 ? val = 0 : val = 1;
		if (t[r].next[val] == 0)
		{
			t[r].next[val] = ++cnt;
			NewNode(t[r].next[val]);
		}
		r = t[r].next[val];
	}
}
int query(int x)
{
	int tar = 0;
	int r = 0;
	for (int i = 31; i >= 0; i--)
	{
		int need = (x & (1 << i));
		need == 0 ? need = 1 : need = 0;
		if (t[r].next[need] != 0)
		{
			tar += (1 << i) * need;
			r = t[r].next[need];
		}
		else
		{
			tar += (1 << i) * (need ^ 1);
			r = t[r].next[need ^ 1];
		}
	}
	return x ^ tar;
}
void dfs(int u, int fa, int XOR)
{
	dis[u] = XOR;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		int d = edge[i].d;
		if (v == fa)
			continue;
		dfs(v, u, XOR ^ d);
	}
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d), add_edge(v, u, d);
		}
		dfs(0, 0, 0);
		for (int i = 0; i < n; i++)
			insert(dis[i]);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, query(dis[i]));
		printf("%d\n", ans);
	}
	return 0;
}