#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Tree
{
	int l, r;
	int val, id;
} t[N * 4];
void push_up(int step)
{
	if (t[step * 2].val <= t[step * 2 + 1].val)
		t[step].val = t[step * 2].val, t[step].id = t[step * 2].id;
	else
		t[step].val = t[step * 2 + 1].val, t[step].id = t[step * 2 + 1].id;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r, t[step].val = 1e9 + 7;
	t[step].id = l;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
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
pair<int, int> query(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
		return make_pair(t[step].val, t[step].id);
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
	{
		pair<int, int> temp1, temp2;
		temp1 = query(l, mid, step * 2), temp2 = query(mid + 1, r, step * 2 + 1);
		pair<int, int> ans;
		ans.first = min(temp1.first, temp2.first);
		if (temp1.first <= temp2.first)
			ans.second = temp1.second;
		else
			ans.second = temp2.second;
		return ans;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int pre_sum = 0;
		int ans = -1e9 + 7, ans_l = 0, ans_r = 0;
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			pre_sum += x;
			pair<int, int> temp = query(1, i, 1);
			int Min = temp.first;
			int pos = 0;
			if (Min < 0)
				pos = temp.second;
			Min = min(0, Min);
			if (pre_sum - Min > ans)
				ans = pre_sum - Min, ans_r = i, ans_l = pos + 1;
			update(i, pre_sum, 1);
		}
		printf("Case %d:\n", ++ ka);
		printf("%d %d %d\n", ans, ans_l, ans_r);
		if (T)
			printf("\n");
	}
}