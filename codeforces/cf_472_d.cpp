#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ,,,

const int N = 2e3 + 7;

struct Edge
{
	int u, v, d;
	Edge(int _u, int _v, int _d) : u(_u) , v(_v), d(_d) {}
	bool operator < (const Edge & rhs) const
	{
		return d < rhs.d;
	}
};
int n;
int Map[N][N];
int fa[N];
vector<Edge>edge;
vector<pair<int, int> > G[N];
int dis[N];
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (fa[a] != fa[b])
		fa[a] = fa[b];
}
bool init()
{
	int flag = 1;
	edge.clear();
	memset(Map, 0, sizeof(Map));
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &Map[i][j]);
			if (i == j && Map[i][j])
				flag = 0;
			if (Map[i][j])
				edge.push_back(Edge(i, j, Map[i][j]));
		}
	}
	if (!flag)
		return false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (Map[i][j] != Map[j][i])
				return false;
		}
	}
	return true;
}
bool kruskal()
{
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++)
	{
		int u = edge[i].u, v = edge[i].v, d = edge[i].d;
		if (find(u) != find(v))
		{
			merge(u, v);
			G[u].push_back(make_pair(v, d));
			G[v].push_back(make_pair(u, d));
		}
	}
	int root = find(1);
	for (int i = 1; i <= n; i++)
	{
		if (find(i) != root)
			return false;
	}
	return true;
}
void dfs(int u, int FA, int d)
{
	dis[u] = d;
	for (auto temp : G[u])
	{
		int v = temp.first;
		int w = temp.second;
		if (v == FA)
			continue;
		dfs(v, u, w + d);
	}
}
bool judge()
{
	for (int i = 1; i <= n; i++)
	{
		memset(dis, 0, sizeof(dis));
		dfs(i, i, 0);
		for (int j = 1; j <= n; j++)
			if (Map[i][j] != dis[j])
				return false;
	}
	return true;
}
int main()
{
	while (scanf("%d", &n) == 1)
	{
		if (init())
		{
			if (kruskal())
			{
				if (judge())
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
	}
}
