#include <bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 6e4 + 7;

struct Tree
{
	int l, r;
	double sum; // sz + l * mid
	int vis;
} t[N * 4];
double MID;
void push_up(int step) { t[step].sum = min(t[step * 2].sum, t[step * 2 + 1].sum); }
void push_down(int step)
{
	if (!t[step].vis)
		return;
	t[step * 2].vis += t[step].vis;
	t[step * 2 + 1].vis += t[step].vis;
	t[step * 2].sum += t[step].vis;
	t[step * 2 + 1].sum += t[step].vis;
	t[step].vis = 0;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r, t[step].sum = t[step].sum = 1.0 * l * MID, t[step].vis = 0;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
}
void update(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
	{
		t[step].vis += 1;
		t[step].sum += 1;
		return;
	}
	push_down(step);
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		update(l, r, step * 2);
	else if (l > mid)
		update(l, r, step * 2 + 1);
	else
		update(l, mid, step * 2), update(mid + 1, r, step * 2 + 1);
	push_up(step);
}
double query(int l, int r, int step)
{
	if (t[step].l == l && r == t[step].r)
		return t[step].sum;
	push_down(step);
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
		return min(query(l, mid, step * 2), query(mid + 1, r, step * 2 + 1));
}
int a[N];
int ap[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", a + i);
		double l = 0, r = 1;
		for (int i = 0; i < 20; i++)
		{
			MID = (l + r) / 2;
			build(1, n, 1);
			memset(ap, 0, sizeof(ap));
			int j;
			for (j = 1; j <= n; j++)
			{
				update(ap[a[j]] + 1, j, 1);
				double res = query(1, j, 1);
				if (res <= (double)MID * (j + 1))
					break;
				ap[a[j]] = j;
			}
			if (j <= n)
				r = MID;
			else
				l = MID;
		}
		printf("%.10lf\n", MID);
	}
}