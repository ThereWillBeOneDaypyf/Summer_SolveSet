#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;
struct Tree
{
	int lt, rt;
	int val;
} t[N * 100];
int cnt = 0;
int root[N];
void init()
{
	cnt = 0;
	memset(root, 0, sizeof(root));
	memset(t, 0, sizeof(t));
}
int NewTreeNode(int y)
{
	++ cnt ;
	t[cnt].lt = t[y].lt;
	t[cnt].rt = t[y].rt;
	t[cnt].val = t[y].val;
	return cnt;
}
void push_up(int step)
{
	t[step].val = t[t[step].lt].val + t[t[step].rt].val;
}
void update(int l, int r, int &x, int y, int pos)
{
	x = NewTreeNode(y);
	if (l == r)
	{
		t[x].val ++;
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid)
		update(l, mid, t[x].lt, t[y].lt, pos);
	else update(mid + 1, r, t[x].rt, t[y].rt, pos);
	push_up(x);
}
int query(int ql, int qr, int l, int r, int x, int y)
{
	if (ql == l && qr == r)
		return t[y].val - t[x].val;
	int mid = (l + r) / 2;
	if (qr <= mid)
		return query(ql, qr, l, mid, t[x].lt, t[y].lt);
	else if (ql > mid)
		return query(ql, qr, mid + 1, r, t[x].rt, t[y].rt);
	else return query(ql, mid, l, mid, t[x].lt, t[y].lt) + query(mid + 1, qr, mid + 1, r, t[x].rt, t[y].rt);
}
vector<int>v, tar;
int GetId(int val)
{
	auto pos = lower_bound(tar.begin(), tar.end(), val);
	if (pos == tar.begin())
		return -1;
	pos --;
	return pos - tar.begin() + 1;
}
int main()
{
	// freopen("1.in", "r", stdin);
	int T;
	// in(T);
	scanf("%d", &T);
	while (T--)
	{
		int n, q;
		// in(n), in(q);
		scanf("%d%d", &n, &q);
		init();
		v.clear(), tar.clear();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			// in(x);
			v.push_back(x);
			tar.push_back(x);
		}
		sort(tar.begin(), tar.end());
		tar.erase(unique(tar.begin(), tar.end()), tar.end());
		for (int i = 0; i < v.size(); i++)
			update(1, n, root[i + 1], root[i], lower_bound(tar.begin(), tar.end(), v[i]) - tar.begin() + 1);
		for (int i = 0; i < q; i++)
		{
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			// printf("n : %d l : %d r : %d k : %d", n, l, r, k);
			// in(l), in(r), in(k);
			// out_str("*l : "), out_int(l), out_str("*r : "), out_int(r), out_str("*k : "), out_int(k);
			// out_char('\n');
			k = GetId(k);
			// printf(" k_again : %d\n", k);
			if (k == -1)
				// out_int(0);
				printf("0\n");
			else
				// out_int(query(1, k, 1, n, root[l - 1], root[r]));
				printf("%d\n", query(1, k, 1, n, root[l - 1], root[r]));
			// out_char('\n');
		}
	}
	// write();
	return 0;
}