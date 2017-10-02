#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Tree
{
	int l, r;
	int gcd;
} t[N * 4];
void push_up(int step)
{
	t[step].gcd = __gcd(t[step * 2].gcd, t[step * 2 + 1].gcd);
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r, t[step].gcd = 0;
	if (l == r)
	{
		scanf("%d", &t[step].gcd);
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
int query(int l, int r, int step)
{
	if (t[step].l == l && r == t[step].r)
		return t[step].gcd;
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l , r, step * 2 + 1);
	else return __gcd(query(l, mid, step * 2), query(mid + 1, r, step * 2 + 1));
}
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		build(1, n, 1);
		for (int i = 0; i < q; i++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", query(l, r, 1));
		}
	}
}