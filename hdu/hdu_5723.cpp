#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...
const int N = 1e5 + 7;
struct Edge
{
	int u, v, d, next;
	bool operator < (const Edge &rhs) const
	{
		return d < rhs.d;
	}
} edge[N * 2];
vector<Edge>e;
int tot = 0;
int head[N], fa[N], sz[N];
int n;
void init()
{
	for (int i = 0; i < N; i++)
		fa[i] = i;
	memset(head, -1, sizeof(head));
	tot = 0;
}
void add_edge(int u, int v, int d)
{
	edge[tot] = {u, v, d, head[u]};
	head[u] = tot ++;
}
int find(int x)
{
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		fa[a] = fa[b];
}
long long kruskal()
{
	init();
	sort(e.begin(), e.end());
	long long res = 0;
	for (int i = 0; i < e.size(); i++)
	{
		int u = e[i].u, v = e[i].v, d = e[i].d;
		if (find(u) != find(v))
		{
			merge(u, v);
			add_edge(u, v, d); add_edge(v, u, d);
			res += 1LL * d;
		}
	}
	return res;
}
double ans = 0;
void dfs(int u, int Fa)
{
	sz[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v, d = edge[i].d;
		if (v == Fa)
			continue;
		dfs(v, u);
		sz[u] += sz[v];
		ans += (double) d * sz[v] * (n - sz[v]);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int m;
		scanf("%d%d", &n, &m);
		if (n <= 1)
		{
			printf("0 0.00\n");
			continue;
		}
		e.clear();
		ans = 0;
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			e.push_back((Edge) {u, v, d, 0});
		}
		long long res = kruskal();
		dfs(1, 1);
		printf("%lld %.2lf\n", res , (2.0 * ans / (double) n / (double)(n - 1)));
	}
}