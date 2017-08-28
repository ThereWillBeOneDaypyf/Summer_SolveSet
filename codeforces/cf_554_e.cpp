#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

struct Edge
{
	int u, v, next;
} edge[N * 2];

int fa[N];
int head[N];
int clr[N];
int tot = 0;
int n, m;

void init()
{
	memset(head, -1, sizeof(head));
	memset(clr, -1, sizeof(clr));
	tot = 0;
	for (int i = 0; i < N; i++)
		fa[i] = i;
}
int find(int x)
{
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
		fa[a] = fa[b];
}
void add_edge(int u, int v)
{
	edge[tot] = {u, v, head[u]};
	head[u] = tot ++;
}
long long pow_mod(int x)
{
	if (x == 0)
		return 1;
	long long temp = pow_mod(x / 2);
	temp = temp * temp % MOD;
	if (x % 2)
		temp = temp * 2 % MOD;
	return temp;
}
vector<pair<int, int> > e;
bool Create_Graph()
{
	for (int i = 0; i < e.size(); i++)
	{
		int u = e[i].first , v = e[i].second;
		if (find(u) == find(v))
			return false;
		add_edge(find(u), find(v));
		add_edge(find(v), find(u));
	}
	return true;
}
bool dfs(int u, int fa, int flag)
{
	clr[u] = flag;
	int ok = 1;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		if (clr[v] == -1)
			ok &= dfs(v, u, flag ^ 1);
		else
			ok &= (clr[v] == (flag ^ 1));
	}
	return ok;
}
int judge_Graph()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (find(i) == i && clr[i] == -1)
		{
			if (!dfs(i, i, 0))
				return 0;
			cnt ++;
		}
	return cnt;
}
int main()
{
	ios :: sync_with_stdio(false);
	while (cin >> n >> m)
	{
		init();
		e.clear();
		for (int i = 0; i < m; i++)
		{
			int u, v, c;
			cin >> u >> v >> c;
			if (c)
				merge(u, v);
			else
				e.push_back(make_pair(u, v));
		}
		if (!Create_Graph())
			cout << 0 << endl;
		else
		{
			int cnt = judge_Graph();
			if (!cnt)
				cout << 0 << endl;
			else
				cout << pow_mod(cnt - 1) % MOD << endl;
		}
	}
}