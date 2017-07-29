#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Edge
{
	int u, v, t, next;
} edge[N * 2];

int head[N];
int tot = 0;
vector<pair<int, int> >leaf;
vector<int>ans;
int broken_cnt[N];
int vis[N];
int deg[N];
int meet[N];
int fa[N];
int is_repair;
void init()
{
	memset(head, -1, sizeof(head));
	memset(meet, 0, sizeof(meet));
	memset(deg, 0, sizeof(deg));
	memset(broken_cnt, 0, sizeof(broken_cnt));
	memset(vis, 0, sizeof(vis));
	leaf.clear();
	ans.clear();
	tot = 0;
}
void add_edge(int u, int v, int t)
{
	edge[tot] = {u, v, t, head[u]};
	head[u] = tot ++;
}
void dfs_break(int u, int Fa, int cnt)
{
	fa[u] = Fa;
	broken_cnt[u] = cnt;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		int t = edge[i].t;
		if (v == Fa)
			continue;
		vis[v] = t - 1;
		dfs_break(v, u, cnt + t - 1);
	}
}
int dfs_repair(int u)
{
	if (u == -1 || broken_cnt[u] <= 0)
		return 0;
	int pre = dfs_repair(fa[u]);
	if (vis[u])
	{
		vis[u] = 0;
		pre++;
	}
	broken_cnt[u] -= pre;
	return pre;
}
// void dfs_repair(int u)
// {
// 	if (u == -1 || meet[u])
// 		return ;
// 	meet[u] = 1;
// 	dfs_repair(fa[u]);
// 	if (vis[u])
// 	{
// 		vis[u] = 0;
// 		is_repair = 1;
// 	}
// 	return ;
// }
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, t;
			scanf("%d%d%d", &u, &v, &t);
			add_edge(u, v, t);
			add_edge(v, u, t);
			deg[u] ++, deg[v] ++;
		}
		dfs_break(1, -1, 0);
		for (int i = 1; i <= n; i++)
			if (deg[i] == 1)
				leaf.push_back(make_pair(broken_cnt[i], i));
		sort(leaf.begin(), leaf.end());
		reverse(leaf.begin(), leaf.end());
		for (auto temp : leaf)
		{
			int u = temp.second;
			is_repair = 0;
			// dfs_repair(u);
			// if (is_repair)
			// 	ans.push_back(u);
			if (dfs_repair(u))
				ans.push_back(u);
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
}