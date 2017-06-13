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
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

struct Edge
{
	int u, v;
	int next;
	int a, b, c;
} edge[N * 2];
struct Query
{
	int u, v, id;
	int next;
} Q[N * 2];
vector<PII>final_q;
int vis[N];
int fa[N];
int ans[N];
int cnt_a[N], cnt_b[N], cnt_c[N];
int head[N];
int qhead[N];
int tot = 0;
int q_tot = 0;
int n;
void init()
{
	final_q.clear();
	tot = 0 ;
	CLR(qhead, -1);
	CLR(vis, 0);
	CLR(fa, 0);
	CLR(ans, 0);
	CLR(cnt_a, 0);
	CLR(cnt_b, 0);
	CLR(cnt_c, 0);
	CLR(head, -1);
}
void add_edge(int u, int v, int a, int b, int c)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].a = a;
	edge[tot].b = b;
	edge[tot].c = c;
	edge[tot].next = head[u];
	head[u] = tot ++ ;
}
void add_Q(int u, int v, int id)
{
	Q[q_tot].u = u;
	Q[q_tot].v = v;
	Q[q_tot].id = id;
	Q[q_tot].next = qhead[u];
	qhead[u] = q_tot ++ ;
}
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void get_inf(int u, int FA)
{
	fa[u] = u;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		int a = edge[i].a;
		int b = edge[i].b;
		int c = edge[i].c;
		if (v == FA)
			continue;
		cnt_a[v] += (cnt_a[u] + a);
		cnt_b[v] += (cnt_b[u] + b);
		cnt_c[v] += (cnt_c[u] + c);
		get_inf(v, u);
	}
}
void lca(int u, int FA)
{
	vis[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == FA)
			continue;
		lca(v, u);
		fa[v] = u;
	}
	for (int i = qhead[u]; i != -1; i = Q[i].next)
	{
		int v = Q[i].v;
		if (vis[v])
		{
			ans[Q[i].id] = find(v);
		}
	}
}
bool judge(int u, int v, int id)
{
	if (cnt_a[u] + cnt_a[v] - 2 * cnt_a[id] < 1 || cnt_b[u] + cnt_b[v] - 2 * cnt_b[id] < 1 || cnt_c[u] + cnt_c[v] - 2 * cnt_c[id] < 1)
		return false;
	return true;
}
int main()
{
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, a, b, c;
			scanf("%d%d%d%d%d", &u, &v, &a, &b, &c);
			add_edge(u, v, a, b, c);
			add_edge(v, u, a, b, c);
		}
		int q;
		get_inf(1, 1);
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_Q(u, v, i);
			add_Q(v, u, i);
			final_q.push_back(mp(u, v));
		}
		lca(1, 1);
		for (int i = 0; i < q; i++)
		{
			// int u = final_q[i].first , v = final_q[i].second;
			// cout << u << " " << v << " " << ans[i] << endl;
			// cout << cnt_a[u] << " " << cnt_b[u] << " " << cnt_c[u] << endl;
			// cout << cnt_a[v] << " " << cnt_b[v] << " " << cnt_c[v] << endl;
			// cout << cnt_a[i] << " " << cnt_b[i] << " " << cnt_c[i] << endl;
			if (judge(final_q[i].first, final_q[i].second, ans[i]))
				printf("Y\n");
			else
				printf("N\n");
		}
	}
}
/*
5
1 2 1 1 1
2 3 0 0 0
3 4 0 0 0
4 5 0 0 0
1
1 4
5
1 2 1 1 1
2 3 0 0 0
3 4 0 0 0
4 5 0 0 0
5
1 2
1 3
2 3
3 4
1 4
 */