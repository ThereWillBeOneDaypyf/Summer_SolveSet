#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

const int N = 1e5 + 7;

struct Tree
{
	int l, r;
	int Max;
} t[N * 4];
struct Node
{
	int l, r;
	bool operator < (const Node & rhs) const
	{
		return l < rhs.l;
	}
};

long long sum[N];

void push_up(int step)
{
	t[step].Max = t[step * 2].Max + t[step * 2 + 1].Max;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r;
	t[step].Max = 0;
	if (l == r)
		return;
	int mid = (l + r)  / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
}
void update(int x, int val, int step)
{
	if (t[step].l == t[step].r)
	{
		t[step].Max ++;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if (x <= mid)
		update(x, val, step * 2);
	else update(x, val, step * 2 + 1);
	push_up(step);
}
int query(int tar, int step)
{
	if (t[step].l == t[step].r)
		return t[step].l;
	int cur = t[step * 2 + 1].Max;
	if (cur >= tar)
		return query(tar, step * 2 + 1);
	else return query(tar - cur, step * 2);
}
int main()
{
	ios :: sync_with_stdio(false);
	int n, m, k;
	while (cin >> n >> k >> m)
	{
		for (int i = 1; i <= n; i++)
			cin >> sum[i];
		for (int i = 1; i <= n; i++)
			sum[i] += sum[i - 1];
		vector<Node> v;
		for (int i = 0; i < m; i++)
		{
			int l, r;
			cin >> l >> r;
			v.push_back({l, r});
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		build(1, n, 1);
		for (int i = 0; i != v.size(); i++)
		{
			update(v[i].r, 1, 1);
			if (i >= k - 1)
			{
				int pos = query(k, 1);
				ans = max(ans, sum[pos] - sum[v[i].l - 1]);
			}
		}
		cout << ans << endl;
	}
}