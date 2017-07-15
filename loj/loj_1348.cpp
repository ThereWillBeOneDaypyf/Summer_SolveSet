#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7 ;

struct Edge
{
	int u, v, next;
} edge[N * 2];
struct Tree
{
	int l, r, sum;
} t[N * 4];
int bigson[N], sz[N], w[N], top[N], deep[N], fa[N];
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
	fa[u] = Fa, sz[u] = 1, deep[u] = d;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == Fa)
			continue;
		dfs(v, u, d + 1);
		sz[u] += sz[v];
		if (bigson[u] == -1 || sz[bigson[u]] < sz[v])
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
	if (deep[u] > deep[v])
		swap(u, v);
	sum += query(w[u], w[v], 1);
	return sum;
}
void debug(int step)
{
	if (t[step].l == t[step].r)
	{
		cout << t[step].sum << " ";
		return;
	}
	debug(step * 2);
	debug(step * 2 + 1);
}
int a[N];
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		printf("Case %d:\n", ++ka);
		int n, q;
		init();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u ++, v++;
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs(1, 1, 0);
		link(1, 1);
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
			update(w[i], a[i], 1);
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int op, x, y;
			scanf("%d%d%d", &op, &x, &y);
			if (op == 0)
				printf("%d\n", get_sum(x + 1, y + 1));
			else
				update(w[x + 1], y, 1);
		}
	}
}