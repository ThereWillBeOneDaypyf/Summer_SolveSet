#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct Tree
{
	int l, r;
	int Max, vis;
} t[N * 4];
int pre_sum[N];
void push_up(int step)
{
	t[step].Max = max(t[step * 2].Max, t[step * 2 + 1].Max);
}
void push_down(int step)
{
	if (t[step].vis == 0)
		return;
	t[step * 2].vis += t[step].vis;
	t[step * 2 + 1].vis += t[step].vis;
	t[step * 2].Max += t[step].vis;
	t[step * 2 + 1].Max += t[step].vis;
	t[step].vis = 0;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r;
	t[step].Max = -2e9;
	t[step].vis = 0;
	if (l == r)
	{
		t[step].Max = pre_sum[l];
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
void update(int l, int r, int val, int step)
{
	if (t[step].l == l && t[step].r == r)
	{
		t[step].vis += val;
		t[step].Max += val;
		return;
	}
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
	if (t[step].l == l && t[step].r == r)
		return t[step].Max;
	push_down(step);
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else return max(query(l, mid, step * 2), query(mid + 1, r, step * 2 + 1));
}
int a[N];
int main()
{
	int n, d;
	while (cin >> n >> d)
	{
		int flag = 1;
		vector<int> zero;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (a[i] == 0)
				zero.push_back(i);
			pre_sum[i] = pre_sum[i - 1] + a[i];
			if (pre_sum[i] > d)
				flag = 0;
		}
		if (!flag)
		{
			cout << -1 << endl;
			continue;
		}
		build(1, n, 1);
		int ans = 0;
		for (auto pos : zero)
		{
			int save = query(pos, pos, 1);
			if (save < 0)
			{
				int need = - save;
				int Max = query(pos, n, 1);
				if (need > d - Max)
				{
					flag = 0;
					break;
				}
				else
				{
					update(pos, n, d - Max, 1);
					ans ++;
				}
			}
		}
		if (!flag)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
}