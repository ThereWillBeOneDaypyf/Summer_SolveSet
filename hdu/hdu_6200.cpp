#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#pragma comment(linker, "/STACK:1024000000,1024000000");
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext()
{
	if (++ps == pe)
		pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T &ans)
{
	ans = 0;
	T f = 1;
	if (ps == pe) return false; //EOF
	do
	{
		rnext();
		if ('-' == *ps) f = -1;
	}
	while (!isdigit(*ps) && ps != pe);
	if (ps == pe) return false; //EOF
	do
	{
		ans = (ans << 1) + (ans << 3) + *ps - 48;
		rnext();
	}
	while (isdigit(*ps) && ps != pe);
	ans *= f;
	return true;
}
const int  MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write()
{
	fwrite(bufout, sizeof(char), pout - bufout, stdout);
	pout = bufout;
}
inline void out_char(char c) { *(pout++) = c; if (pout == pend) write();}
inline void out_str(char *s)
{
	while (*s)
	{
		*(pout++) = *(s++);
		if (pout == pend) write();
	}
}
template <class T>
inline void out_int(T x)
{
	if (!x)
	{
		out_char('0');
		return;
	}
	if (x < 0) x = -x, out_char('-');
	int len = 0;
	while (x)
	{
		outtmp[len++] = x % 10 + 48;
		x /= 10;
	}
	outtmp[len] = 0;
	for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
	out_str(outtmp);
}
const int N = 1e5 + 1;
vector<int>G[N], g[N];
vector<pair<int, int> > edges;
vector<pair<int, int> > e;
int low[N], dfn[N];
int fa[N];
int Index = 0, pos = 0;
int n;
void init()
{
	Index = pos = 0;
	for (int i = 0; i < N; i++)
		G[i].clear(), g[i].clear(), fa[i] = i;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	e.clear();
	edges.clear();
}
void add_edge(int u, int v)
{
	edges.push_back(make_pair(u, v));
	int pos = edges.size() - 1;
	G[u].push_back(edges.size() - 1);
	G[v].push_back(edges.size() - 1);
}
void tarjan(int u, int Fa)
{
	dfn[u] = low[u] = ++ Index;
	for (int i = 0; i != G[u].size(); i ++)
	{
		int id = G[u][i];
		int v;
		if (u == edges[id].first)
			v = edges[id].second;
		else
			v = edges[id].first;
		if (v == Fa)
			continue;
		if (!dfn[v])
		{
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
				e.push_back(make_pair(min(u, v), max(u, v)));
		}
		else low[u] = min(low[u], dfn[v]);
	}
}
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
		fa[a] = b;
}
void Create_g()
{
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i, i);
	for (int i = 0; i < N; i++)
		G[i].clear();
	sort(e.begin(), e.end());
	for (int i = 0; i != edges.size(); i ++)
	{
		int u = edges[i].first, v = edges[i].second;
		vector<pair<int, int> > :: iterator pos = lower_bound(e.begin(), e.end(), make_pair(min(u, v), max(u, v)));
		if (pos == e.end() || *pos != make_pair(min(u, v), max(u, v)))
			merge(u, v);
	}
	edges.clear();
	for (int i  = 0; i != e.size(); i++)
	{
		int u = find(e[i].first), v = find(e[i].second);
		g[u].push_back(v), g[v].push_back(u);
	}
}
// heavy light
int sz[N], f[N], top[N], bigson[N], dep[N], w[N];
void dfs(int u, int Fa, int d)
{
	dep[u] = d, f[u] = Fa, sz[u] = 1, bigson[u] = -1;
	for (int i = 0; i != g[u].size(); i ++)
	{
		int v = g[u][i];
		if (v == Fa)
			continue;
		dfs(v, u, d + 1);
		sz[u] += sz[v];
		if (bigson[u] == -1 || sz[bigson[u]] < sz[v])
			bigson[u] = v;
	}
}
void link(int u, int tp)
{
	top[u] = tp;
	w[u] = ++ pos;
	if (bigson[u] != -1)
		link(bigson[u], tp);
	for (int i = 0; i != g[u].size(); i++)
	{
		int v = g[u][i];
		if (v == f[u] || v == bigson[u])
			continue;
		link(v, v);
	}
}
//segment tree
struct Tree
{
	int vis, sum;
} t[N * 4];
void push_up(int step)
{
	t[step].sum = t[step * 2].sum + t[step * 2 + 1].sum;
}
void push_down(int l, int r, int step)
{
	if (t[step].vis == -1)
		return;
	int mid = (l + r) / 2;
	t[step * 2].vis = t[step * 2 + 1].vis = t[step].vis;
	t[step * 2].sum = (mid - l + 1) * t[step].vis;
	t[step * 2 + 1].sum = (r - (mid + 1) + 1) * t[step].vis;
	t[step].vis = -1;
}
void build(int l, int r, int step)
{
	memset(t, 0, sizeof(t));
	for (int i = 0; i < N * 4; i++)
		t[i].vis = -1;
}
void update(int ql, int qr, int l, int r, int val, int step)
{
	if (ql == l && qr == r)
	{
		t[step].vis = val;
		t[step].sum = (r - l + 1) * val;
		return;
	}
	int mid = (l + r) / 2;
	push_down(l, r, step);
	if (qr <= mid)
		update(ql, qr, l, mid, val, step * 2);
	else if (ql > mid)
		update(ql, qr, mid + 1, r, val, step * 2 + 1);
	else update(ql, mid, l, mid, val, step * 2), update(mid + 1, qr, mid + 1, r, val, step * 2 + 1);
	push_up(step);
}
int query(int ql, int qr, int l, int r, int step)
{
	if (l == ql && r == qr)
		return t[step].sum;
	int mid = (l + r) / 2;
	push_down(l, r, step);
	if (qr <= mid)
		return query(ql, qr, l, mid, step * 2);
	else if (ql > mid)
		return query(ql, qr, mid + 1, r, step * 2 + 1);
	else return query(ql, mid, l, mid, step * 2) + query(mid + 1, qr, mid + 1, r, step * 2 + 1);
}
void change(int u, int v, int val)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		update(w[top[u]], w[u], 1, n, val, 1);
		u = f[top[u]];
	}
	if (u == v)
		return;
	if (dep[u] > dep[v])
		swap(u, v);
	update(w[bigson[u]], w[v], 1, n, val, 1);
}
int get_sum(int u, int v)
{
	int sum = 0;
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]])
			swap(u, v);
		sum += query(w[top[u]], w[u], 1, n, 1);
		u = f[top[u]];
	}
	if (u == v)
		return sum;
	if (dep[u] > dep[v])
		swap(u, v);
	sum += query(w[bigson[u]], w[v], 1, n , 1);
	return sum;
}
int main()
{
	int T;
	freopen("1.in", "r", stdin);
	in(T);
	int ka = 0;
	while (T--)
	{
		int m;
		in(n), in(m);
		init();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			in(u), in(v);
			add_edge(u, v);
		}
		Create_g();
		dfs(find(1), find(1), 0);
		link(find(1), find(1));
		build(1, n, 1);
		for (int i = 0; i != e.size(); i ++)
		{
			int u = e[i].first, v = e[i].second;
			u = find(u), v = find(v);
			//		cout << "*" <<  u << " " << v << endl;
			if (dep[u] < dep[v])
				swap(u, v);
			update(w[u], w[u], 1, n, 1, 1);
			//change(u, u, 1);
		}
		// cout << "*";
		// debug(1);
		// cout << endl;
		int q;
		in(q);
		out_str("Case #"); out_int(++ka); out_str(":\n");
		// for (int i = 1; i <= n; i++)
		// 	cout << i << " " << find(i) << endl;
		for (int i = 0; i < q; i++)
		{
			int op, u, v;
			in(op), in(u), in(v);
			if (op == 1)
			{
				change(find(u), find(v), 0);
				// if (dep[find(u)] < dep[find(v)])
				// 	swap(u, v);
				// change(find(u), find(v), 0);
				// change(find(v), find(v), 1);
			}
			else
				out_int(get_sum(find(u), find(v))), out_char('\n');
			// cout << "*" ;
			// debug(1);
			// cout << endl;
		}
	}
	write();
}
