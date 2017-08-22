#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Edge
{
	int u, v, next;
} edge[N * 2];
struct Query
{
	int l, r, u, t;
};
struct Tree
{
	int l, r, step;
	long long sum;
} t[N * 3 * 4];
long long vv[N], ac[N * 3];
int head[N], dep[N], fa[N][21];
int len = 0, tot = 0;
vector<Query> Q[N];
long long ans[N];
void init()
{
	len = 0, tot = 0;
	memset(head, -1, sizeof(head));
	for (int i = 0; i < N; i++)
		Q[i].clear();
}
void add_edge(int u, int v)
{
	edge[tot] = {u, v, head[u]};
	head[u] = tot ++;
}
void dfs_lca(int u, int Fa, int d)
{
	dep[u] = d, fa[u][0] = Fa;
	for (int i = 1; i < 21; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == Fa)
			continue;
		dfs_lca(v, u, d + 1);
	}
}
int lca(int u, int v)
{
	if (dep[u] < dep[v])
		swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v)
		return u;
	for (int i = 20; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
//tree
void debug(int step)
{
	if (t[step].l == t[step].r)
	{
		cout << t[step].sum << " ";
		return ;
	}
	debug(step * 2);
	debug(step * 2 + 1);
}
void push_up(int step)
{
	t[step].sum = t[step * 2].sum + t[step * 2 + 1].sum;
}
void build(int l, int r, int step)
{
	t[step].l = l , t[step].r = r, t[step].sum = 0;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
void update(int x, long long val, int step)
{
	if (t[step].l == t[step].r)
	{
		t[step].sum += val;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if (x <= mid)
		update(x, val, step * 2);
	else
		update(x, val, step * 2 + 1);
	push_up(step);
}
long long query(int l, int r, int step)
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
int get_id(long long val, int len)
{
	return lower_bound(ac, ac + len, val) - ac + 1;
}
void get_ans(int u, int Fa)
{
	update(get_id(vv[u], len), vv[u], 1);
	for (int i = 0; i < Q[u].size(); i++)
	{
		Query temp = Q[u][i];
		int l = temp.l , r = temp.r , from = temp.u, t = temp.t;
		if (t == 2)
			ans[from] -= 2 * query(get_id(l, len), get_id(r, len), 1);
		else
			ans[from] += query(get_id(l, len), get_id(r, len), 1);
	}
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == Fa)
			continue;
		get_ans(v, u);
	}
	update(get_id(vv[u], len), -vv[u], 1);
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		init();
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", vv + i);
			ac[len ++ ]  = vv[i];
		}
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs_lca(1, 1, 1);
		for (int i = 0; i < m; i++)
		{
			int u, v, a, b;
			scanf("%d%d%d%d", &u, &v, &a, &b);
			ac[len ++] = a, ac[len++] = b;
			int anc = lca(u, v);
			Q[u].push_back((Query) {a, b, i, 0});
			Q[v].push_back((Query) {a, b, i, 1});
			Q[anc].push_back((Query) {a, b, i, 2});
			if (vv[anc] >= a && vv[anc] <= b)
				ans[i] = vv[anc];
			else
				ans[i] = 0;
		}
		sort(ac, ac + len);
		len = unique(ac, ac + len) - ac;
		build(1, len + 1, 1);
		get_ans(1, 1);
		for (int i = 0; i < m; i++)
		{
			if (i)
				printf(" ");
			printf("%lld", ans[i]);
		}
		printf("\n");
	}
}