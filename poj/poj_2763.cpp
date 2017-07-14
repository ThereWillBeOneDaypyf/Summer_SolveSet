#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

struct Edge
{
	int u, v, next;
	int d;
} edge[N * 2], E[N];
struct Tree
{
	int l, r, sum;
} t[N * 4];
int bigson[N], sz[N], deep[N], fa[N], top[N], w[N];
int head[N];
int tot = 0, pos = 0;
void init()
{
	memset(head, -1, sizeof(head));
	memset(bigson, -1, sizeof(bigson));
	tot = 0, pos = 0;;
}
void add_edge(int u, int v, int d)
{
	edge[tot] = {u, v, head[u], d};
	head[u] = tot ++;
}
void dfs(int u, int Fa, int dp)
{
	deep[u] = dp;
	fa[u] = Fa;
	sz[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == Fa)
			continue;
		dfs(v, u, dp + 1);
		if (bigson[u] == -1 || sz[v] > sz[bigson[u]])
			bigson[u] = v;
	}
}
void link(int u, int tp)
{
	top[u] = tp;
	w[u] = ++ pos;
	if (bigson[u] != -1)
		link(bigson[u], tp);
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa[u] || bigson[u] == v)
			continue;
		link(v, v);
	}
}
void push_up(int step)
{
	t[step].sum = t[step * 2].sum + t[step * 2 + 1].sum;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r, t[step].sum = 0;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
}
void update(int x, int val, int step)
{
	if (t[step].l == t[step].r)
	{
		t[step].sum = val;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if (x <= mid)
		update(x, val, step * 2);
	else
		update(x, val, step * 2 + 1);
	push_up(step);
}
int query(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
		return t[step].sum;
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
		return query(l, mid, step * 2) + query(mid + 1, r, step * 2 + 1);
}
int get_sum(int u, int v)
{
	int sum = 0;
	while (top[u] != top[v])
	{
		if (deep[top[u]] < deep[top[v]])
			swap(u, v);
		sum += query(w[top[u]], w[u], 1);
		u = fa[top[u]];
	}
	if (u == v)
		return sum;
	if (deep[u] > deep[v])
		swap(u, v);
	sum += query(w[bigson[u]], w[v], 1);
	return sum;
}
void change(int u, int v, int val)
{
	if (deep[u] > deep[v])
		swap(u, v);
	update(w[v], val, 1);
}
int main()
{
	int n, q, s;
	while (scanf("%d%d%d", &n, &q, &s) == 3)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			E[i].u = u, E[i].v = v, E[i].d = d;
			add_edge(u, v, d);
			add_edge(v, u, d);
		}
		dfs(1, 1, 0);
		link(1, 1);
		build(1, n, 1);
		for (int i = 1; i < n; i++)
		{
			change(E[i].u, E[i].v, E[i].d);
		}
		for (int i = 0; i < q; i++)
		{
			int op;
			int x, y;
			scanf("%d", &op);
			if (op == 0)
			{
				scanf("%d", &x);
				printf("%d\n", get_sum(s, x));
				s = x;
			}
			else
			{
				scanf("%d%d", &x, &y);
				change(E[x].u, E[x].v, y);
			}
		}
	}
}
