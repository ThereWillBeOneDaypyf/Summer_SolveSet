#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Tree
{
	int lt, rt, sum;
} t[N * 40];
int root[N];
int cnt = 0;
void cp(Tree &x, Tree y)
{
	x.lt = y.lt, x.rt = y.rt, x.sum = y.sum;
}
void update(int l, int r, int &x, int y, int k)
{
	cnt ++;
	cp(t[cnt], t[y]);
	t[cnt].sum ++;
	x = cnt;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	if (k <= mid)
		update(l, mid, t[x].lt, t[y].lt, k);
	else
		update(mid + 1, r, t[x].rt, t[y].rt, k);

}
int query(int l, int r, int lt, int rt, int k)
{
	if (l == r)
		return l;
	int sum = t[t[rt].lt].sum - t[t[lt].lt].sum;
	int mid = (l + r) / 2;
	if (sum >= k)
		return query(l, mid, t[lt].lt, t[rt].lt, k);
	else
		return query(mid + 1, r, t[lt].rt, t[rt].rt, k - sum);
}
int a[N], v[N];
int get_id(int x, int num)
{
	return lower_bound(v + 1, v + 1 + num, x) - v;
}
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			v[i] = a[i];
		}
		sort(v + 1, v + 1 + n);
		int num = unique(v + 1, v + n + 1) - v;
		for (int i = 1; i <= n; i++)
			update(1, n, root[i], root[i - 1], get_id(a[i], num));
		for (int i = 0; i < q; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			printf("%d\n", v[query(1, n, root[x - 1], root[y], z)]);
		}
	}
	return 0;
}