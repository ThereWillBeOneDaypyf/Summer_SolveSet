#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 1e5;

vector<pair<int,int> > G[N];
int dis[N],vis[N];
void init()
{
	for(int i = 0;i<N;i++)
		G[i].clear();
}
void add_edge(int u,int v,int d)
{
	G[u].push_back(make_pair(v,d));
}
void spfa(int s)
{
	for(int i = 0;i<N;i++)
		dis[i] = N;
	dis[s] = 0;
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = 0;i<G[u].size();i++)
		{
			int v = G[u][i].first;
			int d = G[u][i].second;
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
	int n;
	while(scanf("%d",&n) == 1)
	{
		init();
		int t = 0;
		for(int i = 0;i < n; i ++)
		{
			int u,v,d;
			cin >> u >> v >> d;
			t = max(t,v + 1);
			add_edge(v + 1, u,-d);
		}
		t ++;
		for(int i = 0;i< t;i++)
			add_edge(t,i,0);
		for(int i = 1;i<t;i++)
		{
			add_edge(i ,i - 1 ,0);
			add_edge(i - 1, i,1);
		}
		spfa(t);
		printf("%d\n",dis[t-1] - dis[0]);
	}
}
