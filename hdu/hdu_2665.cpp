#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Tree
{
	int lt, rt, sum;
} t[N * 20];
int cnt = 0;
int root[N];
void push_up(int step) {t[step].sum = t[t[step].lt].sum + t[t[step].rt].sum;}
void cp(Tree &x, Tree y) {x.sum = y.sum, x.lt = y.lt, x.rt = y.rt;}
void update(int l, int r, int &x, int y, int val)
{
	cnt ++;
	x = cnt;
	cp(t[x], t[y]);
	if (l == r)
	{
		t[x].sum ++;
		return;
	}
	int mid = (l + r) / 2;
	if (val <= mid)
		update(l, mid, t[x].lt, t[y].lt, val);
	else
		update(mid + 1, r, t[x].rt, t[y].rt, val);
	push_up(x);
}
int query(int l, int r, int lt, int rt, int k)
{
	if (l == r)
		return l;
	int cur = t[t[rt].lt].sum - t[t[lt].lt].sum;
	int mid = (l + r) / 2;
	if (cur >= k)
		return query(l, mid, t[lt].lt, t[rt].lt, k);
	else
		return query(mid + 1, r, t[lt].rt, t[rt].rt, k - cur);
}
int v[N], a[N];
int get_id(int val, int len)
{
	return lower_bound(v + 1, v + len, val) - v;
}
void debug(int l, int r, int step)
{
	if (l == r)
	{
		cout << t[step].sum << " " ;
		return;
	}
	int mid = (l + r) / 2;
	debug(l, mid, t[step].lt);
	debug(mid + 1, r, t[step].rt);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(root, 0, sizeof(root));
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			v[i] = a[i];
		}
		sort(v + 1, v + 1 + n);
		int len = unique(v + 1, v + 1 + n) - v;
		for (int i = 1; i <= n; i++)
		{
			update(1, n, root[i], root[i - 1], get_id(a[i], len));
			debug(1, n, root[i]);
			cout << endl;
		}
		for (int i = 0; i < m; i++)
		{
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			printf("%d\n", v[query(1, n, root[l - 1], root[r], k)]);
		}
	}
	return 0;
}