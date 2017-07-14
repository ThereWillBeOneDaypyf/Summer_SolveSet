#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e5 + 7;

struct Edge
{
	int u, v, d;
	int next;
} edge[N * 2], E[N];
struct Tree
{
	int l, r, Max, Min;
	int rev;
} t[N * 4];
int sz[N], bigson[N], top[N], deep[N], fa[N], w[N];
int head[N];
int tot = 0;
int pos = 0;
void init()
{
	memset(head, -1, sizeof(head));
	memset(bigson, -1, sizeof(bigson));
	tot = pos = 0;
}
void add_edge(int u, int v, int d)
{
	edge[tot] = {u, v, d, head[u]};
	head[u] = tot ++;
}
void dfs(int u, int Fa, int d)
{
	deep[u] = d;
	fa[u] = Fa;
	sz[u] = 1;
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
	top[u] = tp;
	w[u] = ++ pos;
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
void push_down(int step)
{
	if (!t[step].rev)
		return;
	t[step * 2].rev ^= 1;
	t[step * 2 + 1].rev ^= 1;
	swap(t[step * 2].Max, t[step * 2].Min);
	swap(t[step * 2 + 1].Max, t[step * 2 + 1].Min);
	t[step * 2].Max = -t[step * 2].Max, t[step * 2].Min = -t[step * 2].Min;
	t[step * 2 + 1].Max = -t[step * 2 + 1].Max, t[step * 2 + 1].Min = -t[step * 2 + 1].Min;
	t[step].rev = 0;
}
void push_up(int step)
{
	t[step].Max = max(t[step * 2].Max, t[step * 2 + 1].Max);
	t[step].Min = min(t[step * 2].Min, t[step * 2 + 1].Min);
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r, t[step].Max = -INF, t[step].Min = INF;
	t[step].rev = 0;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
}
void flip(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
	{
		t[step].rev = 1;
		swap(t[step].Max, t[step].Min);
		t[step].Max = -t[step].Max;
		t[step].Min = -t[step].Min;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		flip(l, r, step * 2);
	else if (l > mid)
		flip(l, r, step * 2 + 1);
	else
		flip(l, mid, step * 2), flip(mid + 1, r, step * 2 + 1);
	push_up(step);
}
void update(int x, int val, int step)
{
	if (t[step].l == t[step].r)
	{
		t[step].Max = t[step].Min = val;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (x <= mid)
		update(x, val, step * 2);
	else
		update(x, val, step * 2 + 1);
	push_up(step);
}
int query(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
		return t[step].Max;
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
		return max(query(l, mid, step * 2), query(mid + 1, r, step * 2 + 1));
}
void change_flip(int u, int v)
{
	while (top[u] != top[v])
	{
		if (deep[top[u]] < deep[top[v]])
			swap(u, v);
		flip(w[top[u]], w[u], 1);
		u = fa[top[u]];
	}
	if (u == v)
		return;
	if (deep[u] > deep[v])
		swap(u, v);
	flip(w[bigson[u]], w[v], 1);
}
void change_val(int u, int v, int val)
{
	if (deep[u] > deep[v])
		swap(u, v);
	update(w[v], val, 1);
}
int get_Max(int u, int v)
{
	int ans = -INF;
	while (top[u] != top[v])
	{
		if (deep[top[u]] < deep[top[v]])
			swap(u, v);
		ans = max(ans, query(w[top[u]], w[u], 1));
		u = fa[top[u]];
	}
	if (u == v)
		return ans;
	if (deep[u] > deep[v])
		swap(u, v);
	ans = max(ans, query(w[bigson[u]], w[v], 1));
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		init();
		int n;
		scanf("%d", &n);
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].d);
			add_edge(E[i].u, E[i].v, E[i].d);
			add_edge(E[i].v, E[i].u, E[i].d);
		}
		dfs(1, 1, 0);
		link(1, 1);
		build(1, n, 1);
		for (int i = 1; i < n; i++)
			change_val(E[i].u, E[i].v, E[i].d);
		char op[10];
		while (scanf("%s", op))
		{
			if (op[0] == 'D')
				break;
			int x, y;
			scanf("%d%d", &x, &y);
			if (op[0] == 'C')
				change_val(E[x].u, E[x].v, y);
			else if (op[0] == 'N')
				change_flip(x, y);
			else
				printf("%d\n", get_Max(x, y));
		}
	}
}