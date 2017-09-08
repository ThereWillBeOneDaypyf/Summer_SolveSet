#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

struct Tree
{
	int l, r;
	int vis;
	int status;
} t[N * 4];
void push_up(int step)
{
	t[step].status = t[step * 2].status | t[step * 2 + 1].status;
}
void push_down(int step)
{
	if (!t[step].vis)
		return;
	t[step * 2].vis = t[step * 2 + 1].vis = t[step * 2].status = t[step * 2 + 1].status = t[step].vis;
	t[step].vis = 0;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r, t[step].status = (1 << 2);
	t[step].vis = 0;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
}
void update(int l, int r, int val, int step)
{
	if (l == t[step].l && r == t[step].r)
	{
		t[step].vis = (1 << val);
		t[step].status = (1 << val);
		return;
	}
	push_down(step);
	int mid = (t[step].l + t[step].r) / 2;
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
	if (l == t[step].l && r == t[step].r)
		return t[step].status;
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
		return (query(l, mid, step * 2) | query(mid + 1, r, step * 2 + 1));
}
int main()
{
	int n, q;
	char op[5];
	while (scanf("%d%d", &n, &q) == 2)
	{
		if (n == 0 && q == 0)
			break;
		build(1, n, 1);
		for (int i = 0; i < q; i++)
		{
			scanf("%s", op);
			int x, y;
			scanf("%d%d", &x, &y);
			if (op[0] == 'P')
			{
				int z ;
				scanf("%d", &z);
				update(x, y, z, 1);
			}
			else
			{
				int status = query(x, y, 1);
				int cnt = 0;
				int a[50];
				for (int i = 1; i <= 30; i++)
					if ((status & (1 << i)))
						a[cnt++] = i;
				for (int i = 0; i < cnt; i++)
				{
					if (i)
						printf(" ");
					printf("%d", a[i]);
				}
				printf("\n");
			}
		}
	}
}