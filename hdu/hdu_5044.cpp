#include<bits/stdc++.h>
using namespace std;
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

const int N = 1e5 + 7;

vector <int> G[N];
vector<pair<int, int> > edge;
int sz[N], fa[N], top[N], bigson[N], deep[N], w[N];
int pos = 0;
long long sump[N], sume[N];
void init()
{
	pos = 0;
	edge.clear();
	memset(sump, 0, sizeof(sump));
	memset(sume, 0, sizeof(sume));
	for (int i = 0; i < N; i++)
		G[i].clear();
}
void add_edge(int u, int v, int d)
{
	G[u].push_back(v);
	G[v].push_back(u);
	edge.push_back(make_pair(u, v));
}

void dfs(int u, int f, int d)
{
	fa[u] = f;
	sz[u] = 1;
	deep[u] = d;
	bigson[u] = -1;
	for (auto v : G[u])
	{
		if (v == f)
			continue;
		dfs(v, u, d + 1);
		if (bigson[u] == -1 || sz[v] > sz[bigson[u]])
			bigson[u] = v;
		sz[u] += sz[v];
	}
}
void link(int u, int tp)
{
	top[u] = tp;
	w[u] = ++ pos;
	if (bigson[u] != -1)
		link(bigson[u], tp);
	for (auto v : G[u])
	{
		if (v == bigson[u] || v == fa[u])
			continue;
		link(v, v);
	}
}
void change(int x, int y, int val, bool is_p)
{
	while (top[x] != top[y])
	{
		if (deep[top[x]] < deep[top[y]])
			swap(x, y);
		if (!is_p)
		{
			sume[w[top[x]]] += val;
			sume[w[x] + 1] -= val;
		}
		else
		{
			sump[w[top[x]]] += val;
			sump[w[x] + 1] -= val;
		}
		x = fa[top[x]];
	}
	if (deep[x] > deep[y])
		swap(x, y);
	if (is_p)
	{
		sump[w[x]] += val;
		sump[w[y] + 1] -= val;
	}
	else
	{
		if (x == y)
			return;
		sume[w[bigson[x]]] += val;
		sume[w[y] + 1] -= val;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		int n, m;
		init();
		scanf("%d%d", &n, &m);
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v, 0);
		}
		dfs(1, 1, 0);
		link(1, 1);
		for (int i = 0; i < m; i++)
		{
			char op[10];
			int u, v, val;
			scanf("%s%d%d%d", op, &u, &v, &val);
			if (op[3] == '1')
				change(u, v, val, 1);
			else
				change(u, v, val, 0);
		}
		printf("Case #%d:\n", ++ka);
		for (int i = 1; i <= n; i++)
			sume[i] += sume[i - 1], sump[i] += sump[i - 1];
		for (int i = 1; i <= n; i ++)
		{
			if (i != 1)
				printf(" ");
			printf("%lld", sump[w[i]]);
		}
		printf("\n");
		for (int i = 0; i < edge.size(); i++)
		{
			if (i)
				printf(" ");
			printf("%lld", deep[edge[i].first] > deep[edge[i].second] ? sume[w[edge[i].first]] :
			       sume[w[edge[i].second]]);
		}
		printf("\n");
	}
}