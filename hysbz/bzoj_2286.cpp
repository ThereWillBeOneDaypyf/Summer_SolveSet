#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...
#define INF 1e18
const int N = 1e6 + 8;
struct Edge
{
	int u, v, next;
	long long d;
} edge[N * 2];
int fa[N][21], dep[N];
int dfn[N], L[N], R[N];
long long dis[N];
int head[N];
int tot = 0, Index = 0;
void init()
{
	tot = 0;
	Index = 0;
	memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, long long d)
{
	edge[tot].u = u, edge[tot].v = v, edge[tot].d = d;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void dfs(int u, int Fa, int d, long long w)
{
	dep[u] = d, dis[u] = w, fa[u][0] = Fa;
	dfn[u] = L[u] = ++ Index;
	for (int i = 1; i <= 20; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		long long ed = edge[i].d;
		if (v == Fa)
			continue;
		dfs(v, u, d + 1, min(w, ed));
	}
	R[u] = ++ Index;
}
int lca(int x, int y)
{
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if (x == y)
		return x;
	for (int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
/* build virtual tree */
int key[N * 2], is_key[N], is_lca[N], st[N];
long long dp[N];
Edge vedge[N * 2];
int vhead[N];
int vtot = 0, top = 0;
void vinit()
{
	vtot = 0;
}
void add_vedge(int u, int v, long long d)
{
	vedge[vtot].u = u, vedge[vtot].v = v, vedge[vtot].d = d, vedge[vtot].next = vhead[u];
	vhead[u] = vtot ++;
}
bool cmp(int u, int v)
{
	return dfn[u] < dfn[v];
}
bool check(int u, int v) // u is in the poth of v
{
	return L[u] <= L[v] && R[v] <= R[u];
}
void tree_up(int u)
{
	long long temp = 0;
	dp[u] = dis[u];
	for (int i = vhead[u]; ~i; i = vedge[i].next)
	{
		int v = vedge[i].v;
		tree_up(v);
		temp += dp[v];
	}
	if (temp)
		dp[u] = min(dp[u], temp);
}
void bulid_vtree()
{
	int k;
	vinit();
	scanf("%d", &k);
	int cnt = 0;
	top = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", key + i);
		cnt ++;
		is_key[key[i]] = 1;
	}
	for (int i = 1; i < k; i++)
	{
		key[cnt++] = lca(key[i], key[i - 1]);
		is_lca[key[cnt - 1]] = 1;
	}
	key[cnt++] = 1;
	sort(key, key + cnt, cmp);
	cnt = unique(key, key + cnt) - key;
	for (int i = 0; i < cnt; i++)
	{
		if (top && !check(st[top], key[i]))
			top --;
		if (top)
		{
			if (!is_key[st[top]])
			{
				add_vedge(st[top], key[i], dis[key[i]]);
				st[++top] = key[i];
			}
		}
		else
			st[++top] = key[i];
	}
	tree_up(1);
	// for (int i = 0; i < vtot; i++)
	// 	cout << vedge[i].u << " " << vedge[i].v << " " << vedge[i].d << endl;
	for (int i = 0; i < cnt; i++)
		is_key[key[i]] = 0, vhead[key[i]] = -1;

}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			long long d;
			scanf("%d%d%lld", &u, &v, &d);
			add_edge(u, v, d);
			add_edge(v, u, d);
		}
		dfs(1, 1, 0, INF);
		int m;
		scanf("%d", &m);
		memset(vhead, -1, sizeof(head));
		for (int i = 0; i < m; i++)
		{
			bulid_vtree();
			printf("%lld\n", dp[1]);
		}
	}
}