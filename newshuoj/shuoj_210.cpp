#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thansk to qhl ...

const int N = 1e5 + 7;

int dis[N];
vector<pair<int, int> >G[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
}
void add_edge(int u, int v, int d)
{
	G[u].push_back(make_pair(v, d));
	G[v].push_back(make_pair(u, d));
}
void dfs(int u, int fa, int pre)
{
	dis[u] = pre;
	for (auto temp : G[u])
	{
		int v = temp.first, d = temp.second;
		if (v == fa)
			continue;
		dfs(v, u, pre ^ d);
	}
}
int main()
{
	int  T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d);
		}
		dfs(1, 1, 1);
		printf("Case %d:\n", ++ka);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d\n", dis[u] ^ dis[v]);
		}
	}
}