#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 4e5 + 8;

int fa[N];
void init()
{
	for (int i = 0; i < N; i++)
		fa[i] = i;
}
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		fa[x] = y;
}
vector<int>G[N];
vector<int>Del;
int DelPoint[N];
int ans[N];
void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		init();
		Del.clear();
		for (int i = 0; i < N; i++)
			G[i].clear();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
		}
		memset(DelPoint, 0, sizeof(DelPoint));
		int k;
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
		{
			int x;
			scanf("%d", &x);
			DelPoint[x] = 1;
			Del.push_back(x);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j != G[i].size(); j++)
			{
				int v = G[i][j];
				if (DelPoint[i] || DelPoint[v])
					continue;
				merge(i, v);
			}
		}
		int connect = 0;
		for (int i  = 0; i < n; i++)
			if (find(i) == i && !DelPoint[i])
				connect ++;
		ans[k] = connect;
		for (int i = k - 1; i >= 0; i--)
		{
			int u = Del[i];
			for (int j = 0; j < G[u].size(); j++)
			{
				int v = G[u][j];
				if (find(u) != find(v) && !DelPoint[v])
				{
					merge(u, v);
					connect -- ;
				}
			}
			connect ++;
			DelPoint[u] = 0;
			ans[i] = connect;
		}
		for (int i = 0; i <= k; i++)
			printf("%d\n", ans[i]);
	}
}