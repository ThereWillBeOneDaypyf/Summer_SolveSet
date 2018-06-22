#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

vector<int> G[N];
int L[N], R[N];
int tot;
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
	tot = 0;
}
int add_edge(int u, int v)
{
	G[u].push_back(v);
}
void dfs(int u, int fa)
{
	L[u] = ++ tot;
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
	}
	R[u] = tot;
}
struct Tree
{
	int l, r;
	int cnt[2];
	int vis;
} t[N * 4];
void push_up(int step)
{
	for (int i = 0; i < 2; i++)
		t[step].cnt[i] = t[step * 2].cnt[i] + t[step * 2 + 1].cnt[i];
}
void push_down(int step)
{
	if (!t[step].vis)
		return;
	swap(t[step * 2].cnt[0], t[step * 2].cnt[1]);
	swap(t[step * 2 + 1].cnt[0], t[step * 2 + 1].cnt[1]);
	t[step * 2].vis ^= 1;
	t[step * 2 + 1].vis ^= 1;
	t[step].vis = 0;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r;
	t[step].vis = 0;
	if (t[step].l == t[step].r)
	{
		t[step].cnt[0] = 1;
		t[step].cnt[1] = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
void update(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
	{
		t[step].vis ^= 1;
		swap(t[step].cnt[0] , t[step].cnt[1]);
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		update(l , r, step * 2);
	else if (l > mid)
		update(l, r, step * 2 + 1);
	else
		update(l, mid, step * 2), update(mid + 1, r, step * 2 + 1);
	push_up(step);
}
int query(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
		return t[step].cnt[1];
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
		return query(l, mid, step * 2) + query(mid + 1, r, step * 2 + 1);
}
void debug(int step)
{
	if (t[step].l == t[step].r)
	{
		cout << t[step].cnt[1] << " ";
		return;
	}
	push_down(step);
	debug(step * 2);
	debug(step * 2 + 1);
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 2; i <= n; i++)
		{
			int f;
			scanf("%d", &f);
			G[f].push_back(i);
		}
		dfs(1, 1);
		build(1, tot, 1);
		for (int i = 1; i <= n; i++)
		{
			int flag;
			scanf("%d", &flag);
			if (flag)
				update(L[i], L[i], 1);
		}
		char op[10];
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int x;
			scanf("%s%d", op, &x);
			if (op[0] == 'g')
				printf("%d\n", query(L[x], R[x], 1));
			else
				update(L[x], R[x], 1);
			// debug(1);
			// cout << endl;
		}
	}
}