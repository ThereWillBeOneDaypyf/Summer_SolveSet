#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;

//thanks to pyf ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

struct Edge
{
	int u, v, next;
} edge[N * 2];
struct Query
{
	int id, u, v, lca, next;
	bool if_out;
} Q[N * 2];

int tot = 0;
int q_tot = 0;
int head[N];
int qhead[N];
int vis[N];
int anc[N];
int fa[N];
int indeg[N];
int ans[N];
void init()
{
	CLR(ans, 0);
	CLR(anc, 0);
	CLR(indeg, 0);
	CLR(Q, 0);
	CLR(edge, 0);
	CLR(vis, 0);
	CLR(head, -1);
	CLR(qhead, -1);
	tot = 0;
	q_tot = 0;
	for (int i = 0; i < N; i++)
		fa[i] = i;
}
void add_edge(int u, int v)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void add_q(int u, int v, int id)
{
	Q[q_tot].if_out = 0;
	Q[q_tot].u = u;
	Q[q_tot].v = v;
	Q[q_tot].next = qhead[u];
	Q[q_tot].id = id;
	qhead[u] = q_tot ++;
}
int find(int x)
{
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int u, int v)
{
	u  = find(u);
	v = find(v);
	if (u != v)
		fa[u] = v;
}
void lca(int u)
{
	fa[u] = u;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		lca(v);
		fa[v] = u;
		// merge(u, v);
		// anc[find(u)] = u;
	}
	vis[u] = 1;
	for (int i = qhead[u]; i != -1; i = Q[i].next)
	{
		int v = Q[i].v;
		if (vis[v])
		{
			Q[i].if_out = 1;
			//	ans[Q[i].id] = anc[find(v)];
			ans[Q[i].id] = find(v);
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		int n;
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			indeg[v] ++ ;
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int q_u, q_v;
			scanf("%d%d", &q_u, &q_v);
			add_q(q_u, q_v, i);
			add_q(q_v, q_u, i);
		}
		for (int i = 0; i <= n; i++)
			if (!indeg[i])
				lca(i);
		int cnt = 0;
		printf("Case %d:\n", ++ka);
		for (int i = 0; i < m; i++)
		{
			printf("%d", ans[i]);
			i == m - 1 ? printf("\n") : printf(" ");
		}
		// for (int i = 0; i < q_tot; i++)
		// {
		// 	if (Q[i].if_out)
		// 	{
		// 		cnt ++ ;
		// 		printf("%d", Q[i].lca);
		// 		if (cnt == m)
		// 		{
		// 			printf("\n");
		// 			break;
		// 		}
		// 		else	printf(" ");
		// 	}
		// }
	}
}
