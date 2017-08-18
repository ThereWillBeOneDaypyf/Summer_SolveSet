#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Tree
{
	int l, r;
	int Gcd;
} t[N * 4];
int a[N];
void push_up(int step)
{
	t[step].Gcd = __gcd(t[step * 2].Gcd, t[step * 2 + 1].Gcd);
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r;
	if (l == r)
	{
		scanf("%d", &t[step].Gcd);
		a[l] = t[step].Gcd;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
int query(int l, int r, int step)
{
	if (l == t[step].l && r == t[step].r)
		return t[step].Gcd;
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
		return __gcd(query(l, mid, step * 2), query(mid + 1, r, step * 2 + 1));
}
map<int, long long>interval_gcd[N + 5];
map<int, long long>cnt;
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		int n;
		scanf("%d", &n);
		build(1, n, 1);
		for (int i = 1; i <= n; i++)
			interval_gcd[i].clear();
		cnt.clear();
		interval_gcd[1][a[1]] ++;
		cnt[a[1]]++;
		for (int i = 2; i <= n; i++)
		{
			interval_gcd[i][a[i]] ++;
			cnt[a[i]] ++;
			for (map<int, long long> :: iterator it = interval_gcd[i - 1].begin(); it != interval_gcd[i - 1].end(); it++)
			{
				int cur_gcd = __gcd(it->first, a[i]);
				interval_gcd[i][cur_gcd] += it -> second;
				cnt[cur_gcd] += it -> second;
			}
		}
		int q;
		scanf("%d", &q);
		printf("Case #%d:\n", ++ka);
		for (int i = 0; i < q; i++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int GCD = query(l, r, 1);
			printf("%d %lld\n", GCD, cnt[GCD]);
		}
	}
}