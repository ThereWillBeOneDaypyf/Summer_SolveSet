#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

typedef pair<int,int> PII;

const int N = 1e3 + 20;
int g[N][N];
int vis[N];
int dis[N];

void spfa(int s,int n)
{
	for(int i = 1;i<=n;i++)
		i == s ? dis[i] = 0 : dis[i] = INF;
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = 1;i<=n;i++)
		{
			if (!g[u][i]) continue;
			int v = i;
			int d = g[u][i];
			if(dis[u] + d < dis[v])
			{
				dis[v] = dis[u] + d;
				if(!vis[v])
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
//	freopen("1.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	int n,m;
	while(cin >> m >> n)
	{
		memset(g, 0, sizeof(g));
		for(int i = 0;i < m;i++)
		{
			int u,v,d;
			cin >> u >> v >> d;
			if (!g[u][v]) g[v][u] = g[u][v] = d;
			else g[v][u] = g[u][v] = min(g[u][v], d);
		}
		spfa(1,n);
		cout << dis[n] << endl;
	}
}
