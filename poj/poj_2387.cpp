#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e5 + 8;

struct Edge
{
	int u, v, d, next;
} edge[N * 2];

int dis[N], vis[N];
int head[N];
int tot = 0;

void init()
{
	tot = 0;
	memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, int d)
{
	edge[tot] = {u, v, d, head[u]};
	head[u] = tot ++;
}
void spfa(int s, int n)
{
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	for (int i = 1; i <= n; i++)
		i == s ? dis[i] = 0 : dis[i] = INF;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; ~i; i = edge[i].next)
		{
			int v = edge[i].v;
			int d = edge[i].d;
			if (dis[v] > dis[u] + d)
			{
				dis[v] = dis[u] + d;
				if (!vis[v])
				{
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			add_edge(u, v, d);
			add_edge(v, u, d);
		}
		spfa(n, n);
		cout << dis[1] << endl;
	}
}