#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
#define INF 0x3f3f3f3f
const int N = 3e6 + 7;

struct Tree
{
	int lt, rt, l, r, x;
} t[N];
int root[51];
int cnt = 0;
void push_up(int r)
{
	t[r].x = min(t[t[r].lt].x, t[t[r].rt].x);
}

int init_Node(int l, int r, int x)
{
	cnt ++;
	t[cnt].l = l, t[cnt].r = r, t[cnt].x = x;
	t[cnt].lt = t[cnt].rt = 0;
	return cnt;
}
void build()
{
	t[0].lt = t[0].rt = t[0].l = t[0].r = 0;
	t[0].x = 0x3f3f3f3f;
	memset(root, 0, sizeof(root));
	cnt = 0;
	for (int i = 0; i <= 50; i++)
		root[i] = init_Node(1, 1000001, 0x3f3f3f3f);
}
void update(int pos, int val, int r)
{
	t[r].x = min(t[r].x, val);
	if (t[r].l == t[r].r)
		return;
	int mid = (t[r].l + t[r].r) / 2;
	if (pos <= mid)
	{
		if (!t[r].lt)
			t[r].lt = init_Node(t[r].l, mid, val);
		update(pos, val, t[r].lt);
	}
	else
	{
		if (!t[r].rt)
			t[r].rt = init_Node(mid + 1, t[r].r, val);
		update(pos, val, t[r].rt);
	}
	push_up(r);
}
int query(int ql, int qr, int r)
{
	if (ql == t[r].l && qr == t[r].r)
		return t[r].x;
	int mid = (t[r].l + t[r].r) / 2;
	if (qr <= mid)
	{
		if (!t[r].lt)
			return INF;
		else
			return query(ql, qr, t[r].lt);
	}
	else if (ql > mid)
	{
		if (!t[r].rt)
			return INF;
		else
			return query(ql, qr, t[r].rt);
	}
	else
	{
		int ans = INF;
		if (t[r].lt)
			ans = min(ans, query(ql, mid, t[r].lt));
		if (t[r].rt)
			ans = min(ans, query(mid + 1, qr, t[r].rt));
		return ans;
	}
}
int main()
{
	build();
	int op, x, y, z;
	while (scanf("%d", &op) == 1)
	{
		if (op == 3)
			break;
		else if (op == 0)
			build();
		else if (op == 1)
		{
			scanf("%d%d%d", &x, &y, &z);
			update(y, x, root[z]);
		}
		else if (op == 2)
		{
			int ans = 0;
			scanf("%d%d%d", &x, &y, &z);
			for (int i = 0; i <= 50; i++)
			{
				int cur = query(y, z, root[i]);
				ans += (cur <= x);
			}
			printf("%d\n", ans);
		}
	}
}