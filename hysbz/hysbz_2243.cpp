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
} edge[N * 2];
struct Tree
{
	int l, r;
	int lclr, rclr, vis;
	int sum;
} t[N * 4];

int bigson[N], top[N], sz[N], fa[N], deep[N], w[N];
int head[N];
int tot = 0, pos = 0;
void init()
{
	memset(head, -1, sizeof(head));
	memset(bigson, -1, sizeof(bigson));
	tot = pos = 0;
}
void add_edge(int u, int v)
{
	edge[tot].u = u, edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void dfs(int u, int Fa, int d)
{
	fa[u] = Fa, deep[u] = d, sz[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == Fa)
			continue;
		dfs(v, u, d + 1);
		sz[u] += sz[v];
		if (bigson[u] == -1 || sz[v] > sz[bigson[u]])
			bigson[u] = v;
	}
}
void link(int u, int tp)
{
	w[u] = ++ pos;
	top[u] = tp;
	if (bigson[u] != -1)
		link(bigson[u], tp);
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa[u] || v == bigson[u])
			continue;
		link(v, v);
	}
}
void push_up(int step)
{
	t[step].lclr = t[step * 2].lclr;
	t[step].rclr = t[step * 2 + 1].rclr;
	t[step].sum = t[step * 2].sum + t[step * 2 + 1].sum;
	if (t[step * 2].rclr == t[step * 2 + 1].lclr)
		t[step].sum --;
}
void push_down(int step)
{
	if (t[step].vis == -1)
		return;
	t[step * 2].vis = t[step * 2 + 1].vis = t[step].vis;
	t[step * 2].sum = t[step * 2 + 1].sum = 1;
	t[step * 2].lclr = t[step * 2].rclr = t[step * 2 + 1].lclr = t[step * 2 + 1].rclr = t[step].vis;
	t[step].vis = -1;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r, t[step].lclr = t[step].rclr = t[step].sum = 0;
	t[step].vis = -1;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
}
void update(int l, int r, int val, int step)
{
	if (t[step].l == l && t[step].r == r)
	{
		t[step].vis = val;
		t[step].sum = 1;
		t[step].lclr = t[step].rclr = val;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		update(l, r, val, step * 2);
	else if (l > mid)
		update(l, r, val, step * 2 + 1);
	else
		update(l, mid, val, step * 2), update(mid + 1, r, val, step * 2 + 1);
	push_up(step);
}
int query(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
		return t[step].sum ;
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
	{
		int sum = query(l, mid, step * 2) + query(mid + 1, r, step * 2 + 1);
		if (t[step * 2].rclr == t[step * 2 + 1].lclr)
			sum --;
		return sum;
	}
}
int query_clr(int x, int step)
{
	if (t[step].l == t[step].r)
		return t[step].lclr;
	int mid = (t[step].l + t[step].r)  / 2;
	push_down(step);
	if (x <= mid)
		return query_clr(x, step * 2);
	else
		return query_clr(x, step * 2 + 1);
}
void change_val(int u, int v, int val)
{
	while (top[u] != top[v])
	{
		if (deep[top[u]] < deep[top[v]])
			swap(u, v);
		update(w[top[u]], w[u], val, 1);
		u = fa[top[u]];
	}
	if (deep[u] > deep[v])
		swap(u, v);
	update(w[u], w[v], val, 1);
}
int query_sum(int u, int v)
{
	int sum = 0;
	while (top[u] != top[v])
	{
		if (deep[top[u]] < deep[top[v]])
			swap(u, v);
		sum += query(w[top[u]], w[u], 1);
		int clr1 = query_clr(w[top[u]], 1), clr2 = query_clr(w[fa[top[u]]], 1);
		if (clr1 == clr2)
			sum --;
		u = fa[top[u]];
	}
	if (deep[u] > deep[v])
		swap(u, v);
	sum += query(w[u], w[v], 1);
	return sum;
}
int va[N];
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d", va + i);
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs(1, 1, 0);
		link(1, 1);
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
			update(w[i], w[i], va[i], 1);
		for (int i = 0; i < q; i++)
		{
			char op[10];
			int x, y, z;
			scanf("%s", op);
			if (op[0] == 'Q')
			{
				scanf("%d%d", &x, &y);
				printf("%d\n", query_sum(x, y));
			}
			else
			{
				scanf("%d%d%d", &x, &y, &z);
				change_val(x, y, z);
			}
		}
	}
}
