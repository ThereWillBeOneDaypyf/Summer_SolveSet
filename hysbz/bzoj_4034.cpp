#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Tree
{
	int l, r;
	long long sum, vis;
	int step;
} t[N * 4];

void push_down(int step)
{
	if (!t[step].vis)
		return;
	t[step * 2].vis += t[step].vis;
	t[step * 2 + 1].vis += t[step].vis;
	t[step * 2].sum += 1LL * t[step].vis * (t[step * 2].r - t[step * 2].l + 1);
	t[step * 2 + 1].sum += 1LL * t[step].vis * (t[step * 2 + 1].r - t[step * 2 + 1].l + 1);
	t[step].vis = 0;
}
void push_up(int step)
{
	t[step].sum = t[step * 2].sum + t[step * 2 + 1].sum;
}
void build(int l, int r, int step)
{
	t[step].l = l , t[step].r = r;
	t[step].sum = 0, t[step].vis = 0;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
void update(int l, int r, int val, int step)
{
	if (l == t[step].l && r == t[step].r)
	{
		t[step].vis += val;
		t[step].sum += 1LL * val * (r - l + 1);
		return;
	}
	push_down(step);
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		update(l, r, val, step * 2);
	else if (l > mid)
		update(l, r, val, step * 2 + 1);
	else update(l, mid, val, step * 2), update(mid + 1, r, val, step * 2 + 1);
	push_up(step);
}
long long query(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
		return t[step].sum;
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else return query(l, mid, step * 2) + query(mid + 1, r, step * 2 + 1);
}
//Decompositiom
vector<int>G[N];
int fa[N], top[N], L[N], R[N];
int bigson[N], sz[N], dep[N];
int pos = 0;
void init()
{
	pos = 0;
	for (int i = 0; i < N; i++)
		G[i].clear();
}
void dfs(int u, int Fa, int d)
{
	dep[u] = d, sz[u] = 1, fa[u] = Fa;
	bigson[u] = -1;
	for (int i = 0; i != G[u].size(); i++)
	{
		int v = G[u][i];
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
	L[u] = ++ pos;
	top[u] = tp;
	if (bigson[u] != -1)
		link(bigson[u], tp);
	for (int i = 0; i != G[u].size(); i++)
	{
		int v = G[u][i];
		if (v == fa[u] || v == bigson[u])
			continue;
		link(v, v);
	}
	R[u] = pos;
}
long long GetSum(int x, int y)
{
	long long sum = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		sum += query(L[top[x]], L[x], 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y])
		swap(x, y);
	sum += query(L[x], L[y], 1);
	return sum;
}
int a[N];
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 1, 0);
		link(1, 1);
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
			update(L[i], L[i], a[i], 1);
		for (int i = 0; i < m; i++)
		{
			int op, x, a;
			scanf("%d", &op);
			if (op == 3)
			{
				scanf("%d", &x);
				printf("%lld\n", GetSum(1, x));
			}
			else
			{
				scanf("%d%d", &x, &a);
				if (op == 1)
					update(L[x], L[x], a, 1);
				else if (op == 2)
					update(L[x], R[x], a, 1);
			}
		}
	}
}