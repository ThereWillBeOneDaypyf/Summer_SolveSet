#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

//thanks to pyf ...

#define N 100010

struct Edge
{
	int u, v, next;
	bool cut;
} edge[N * 3];

int head[N];
int dfn[N];
int low[N];
vector<pair<int, int> > ans;
int n;
int tot = 0;
int Index = 0;
int bridge = 0;

void init()
{
	ans.clear();
	memset(head, -1, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	Index = 0;
	tot = 0;
	bridge = 0;
}

void add_edge(int u, int v)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	edge[tot].cut = 0;
	head[u] = tot++;
}

void tarjan(int u, int fa)
{
	dfn[u] = low[u] = ++ Index ;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (v == fa)
			continue;
		if (!dfn[v])
		{
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
			{
				bridge ++ ;
				edge[i].cut = 1;
				edge[i ^ 1].cut = 1;
//				cout << u << " " << v << endl;
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}
void solve()
{
	for (int i = 0; i < n; i++)
	{
		if (!dfn[i])
		{
			tarjan(i, i);
		}
	}
	printf("%d critical links\n", bridge);
	for (int i = 0; i < n; i++)
	{
		for (int j = head[i]; j != -1; j = edge[j].next)
		{
			if (edge[j].cut && i < edge[j].v)
			{
				ans.push_back(make_pair(i, edge[j].v));
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%d - %d\n", ans[i].first, ans[i].second);
	cout << endl;
}
int main()
{
	while (cin >> n)
	{
		init();
		for (int i = 0; i < n; i++)
		{
			int u, v;
			int num;
			scanf("%d (%d)", &u, &num);
			for (int j = 0; j < num; j++)
			{
				cin >> v;
				add_edge(u, v);
				add_edge(v, u);
			}
		}
		solve();
	}
}