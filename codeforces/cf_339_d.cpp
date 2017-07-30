#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;

struct Tree
{
	int l, r, flag;
	int val;
} t[N * 4];
void push_up(int step) // 1 or 0 xor
{
	if (t[step].flag)
		t[step].val = (t[step * 2].val | t[step * 2 + 1].val);
	else
		t[step].val = (t[step * 2].val ^ t[step * 2 + 1].val);
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r, t[step].flag = 0;
	if (l == r)
	{
		t[step].flag = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	t[step].flag = t[step * 2].flag ^ 1;
}
void update(int x, int val, int step)
{
	if (t[step].l == t[step].r)
	{
		t[step].val = val;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if (x <= mid)
		update(x, val, step * 2);
	else
		update(x, val, step * 2 + 1);
	push_up(step);
}
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		n = 1 << n;
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			update(i, x, 1);
		}
		for (int i = 1; i <= q; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			update(x, y, 1);
			printf("%d\n", t[1].val);
		}
	}
}