#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;
int pos[N];
struct Query
{
	int l, r, id;
	bool operator < (const Query &rhs) const
	{
		return pos[l] < pos[rhs.l] || (pos[l] == pos[rhs.l] && r < rhs.r);
	}
} Q[N];
int BIT[N];
int ans[N];
int tar[N];
int a[N];
int cur_ans = 0;
int n, cnt;
int lowbit(int x)
{
	return x & (-x) ;
}
void update(int x, int val)
{
	while (x <= n)
	{
		BIT[x] += val;
		x += lowbit(x);
	}
}
int query(int x)
{
	int ans = 0;
	while (x > 0)
	{
		ans += BIT[x];
		x -= lowbit(x);
	}
	return ans;
}
int get_id(int x)
{
	return lower_bound(tar, tar + cnt, x) - tar;
}
void left_add(int pos, int kind)
{
	cur_ans += kind * query(get_id(a[pos]) - 1);
	update(get_id(a[pos]), kind);
}
void right_add(int pos, int kind)
{
	cur_ans += kind * (query(n) - query(get_id(a[pos])));
	update(get_id(a[pos]), kind);
}
int main()
{
	int block;
	while (scanf("%d", &n) == 1)
	{
		block = ceil(sqrt(1.0 * n));
		memset(BIT, 0, sizeof(BIT));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			tar[i] = a[i];
			pos[i] = i / block;
		}
		sort(tar + 1, tar + 1 + n);
		cnt = unique(tar + 1, tar + 1 + n) - tar;
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			Q[i].l = l , Q[i].r = r, Q[i].id = i;
		}
		sort(Q, Q + q);
		cur_ans = 0;
		int l = 2, r = 1;
		for (int i = 0; i < q; i++)
		{
			while (l > Q[i].l) left_add(--l, 1);
			while (r < Q[i].r) right_add(++r, 1);
			while (l < Q[i].l) left_add(l++, -1);
			while (r > Q[i].r) right_add(r--, -1);
			ans[Q[i].id] = cur_ans;
		}
		for (int i = 0; i < q; i++)
			printf("%d\n", ans[i]);
	}
}