#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct Tree
{
	int l, r;
	int Max;
} t[N * 4];

void push_up(int step)
{
	t[step].Max = max(t[step * 2].Max, t[step * 2 + 1].Max);
}

void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r;
	t[step].Max = 0;
	if (l == r)
	{
		scanf("%d", &t[step].Max);
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
void update(int x, int step)
{
	if (t[step].l == t[step].r)
	{
		t[step].Max ++;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if (x <= mid)
		update(x, step * 2);
	else
		update(x, step * 2 + 1);
	push_up(step);
}
int query(int val, int step)
{
	if (t[step].l == t[step].r)
		return t[step].l;
	if (t[step * 2].Max >= val)
		return query(val, step * 2);
	else
		return query(val, step * 2 + 1);
}
void Output(int step)
{
	if (t[step].l == t[step].r)
	{
		printf("%d\n", t[step].Max);
		return;
	}
	Output(step * 2);
	Output(step * 2 + 1);
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		build(1, n, 1);
		for (int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);
			if (x > t[1].Max)
				continue;
			else
			{
				int pos = query(x, 1);
				if (pos == 1)
					continue;
				else
					update(pos - 1, 1);
			}
		}
		Output(1);
		printf("\n");
	}
}
