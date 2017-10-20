#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int dis[N];
int dep[N * 4];
int dp[N * 4][22];
int rec[N * 4];
int first[N];
int LOG2[N * 4];
int tot = 0;
vector<pair<int, int> > G[N];

void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
	for (int i = 0; i < 4 * N; i++)
		LOG2[i] = (i == 0 ? -1 : LOG2[i >> 1] + 1);
	tot = 0;
}
void add_edge(int u, int v, int d)
{
	G[u].push_back(make_pair(v, d));
	G[v].push_back(make_pair(u, d));
}
void dfs(int u, int fa, int d, int w)
{
	dis[u] = w;
	first[u] = ++ tot;
	rec[tot] = u;
	dep[tot] = d;
	for (int i = 0; i != G[u].size(); i++)
	{
		int v = G[u][i].first;
		int dd = G[u][i].second;
		if (v == fa)
			continue;
		dfs(v, u, d + 1, w + dd);
		rec[++ tot] = u;
		dep[tot] = d;
	}
}
void init_st()
{
	for (int i = 1; i <= tot; i++)
		dp[i][0] = i;
	for (int j = 1; (1 << j) <= tot; j++)
	{
		for (int i = 1; i + (1 << j) <= tot + 1; i++)
		{
			int a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
			dp[i][j] = dep[a] < dep[b] ? a : b;
		}
	}
}
int rmq(int l, int r)
{
	int k = LOG2[r - l + 1];
	int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
	return dep[a] < dep[b] ? a : b;
}

int lca(int u, int v)
{
	int x = first[u], y = first[v];
	if (x > y)
		swap(x, y);
	int res = rmq(x, y);
	return rec[res];
}
//Seg Tree
struct Line
{
	int u, v;
};
struct Tree
{
	int l, r;
	Line Max;
} t[N * 4];
Line merge(Line a, Line b)
{
	vector<int> v{a.u, a.v, b.u, b.v};
	Line ans;
	ans.u = a.u, ans.v = a.v;
	int Max = dis[a.u] + dis[a.v] - 2 * dis[lca(a.u, a.v)];
	//cout << " ******************* " << endl;
	for (int i = 0 ; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			int x = v[i], y = v[j];
			if (x == y)
				continue;
			int Len = dis[x] + dis[y] - 2LL * dis[lca(x, y)];
			//		cout << ans.u << " " << ans.v << " " << x << " " << y << " " << Max << " " << Len << endl;
			if (Len > Max)
			{
				Max = Len;
				ans.u = x, ans.v = y;
			}
		}
	}
	//cout << " ****************** " << Max << " " << ans.u << " " << ans.v << endl;
	return ans;
}
void push_up(int step)
{
	t[step].Max = merge(t[step * 2].Max, t[step * 2 + 1].Max);
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r;
	if (l == r)
	{
		t[step].Max = {l, l};
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
Line query(int l, int r, int step)
{
	if (t[step].l == l && t[step].r == r)
		return t[step].Max;
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
	{
		Line Max = merge(query(l, mid, step * 2), query(mid + 1, r, step * 2 + 1));
		return Max;
	}
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d);
		}
		dfs(1, 1, 0, 0);
		init_st();
		memset(t, 0, sizeof(t));
		build(1, n, 1);
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int a, b, x, y;
			scanf("%d%d%d%d", &a, &b, &x, &y);
			Line l1 = query(a, b, 1);
			Line l2 = query(x, y, 1);
			vector<int> p1{l1.u, l1.v}, p2{l2.u, l2.v};
			int ac = 0;
			for (auto t1 : p1)
				for (auto t2 : p2)
				{
					ac = max(ac, dis[t1] + dis[t2] - 2 * dis[lca(t1, t2)]);
					//		cout << t1 << " " << t2 << " " << lca(t1, t2) << " " << ac << endl;
				}
			// cout << l1.u << " " << l1.v << endl;
			// cout << l2.u << " " << l2.v << endl;
			// cout << ans.u << " " << ans.v << " " << lca(ans.u, ans.v) << endl;
			printf("%d\n", ac);
		}
	}
}