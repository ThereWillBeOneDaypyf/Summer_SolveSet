#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 2e5 + 7;

struct Edge
{
	int u, v, next;
} edge[N * 2];

int sz[N], Min, Mx[N];
int head[N];
int tot = 0;
int ans;
void init()
{
	tot = 0;
	Min = INF;
	memset(head, -1, sizeof(head));
	memset(sz, 0, sizeof(sz));
}
void add_edge(int u, int v)
{
	edge[tot].u = u, edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void get_sz(int u, int fa)
{
	sz[u] = 1;
	Mx[u] = 0;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		get_sz(v, u);
		sz[u] += sz[v];
		Mx[u] = max(Mx[u], sz[v]);
	}
}
void get_root(int r, int u, int fa)
{
	Mx[u] = max(Mx[u], sz[r] - sz[u]);
	if (Min > Mx[u] || (Min == Mx[u] && u < ans))
		ans = u, Min = Mx[u];
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		get_root(r, v, u);
	}
}
vector<int>tar;
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		get_sz(1, 0);
		get_root(1, 1, 0);
		tar.clear();
		for (int i = 1; i <= n; i++)
			if (Mx[i] == Mx[ans])
				tar.push_back(i);
		for (int i = 0; i < tar.size(); i++)
		{
			if (i)
				printf("%s", " ");
			printf("%d", tar[i]);
		}
		printf("\n");
	}
}
