#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 8;

vector<pair<int,int> >G[N];


void init()
{
	for(int i = 0;i < N;i++)
		G[i].clear();
}
void add_edge(int u,int v,int d)
{
	G[u].push_back(make_pair(v,d));
}
int dis[N];
int cnt[N];
int vis[N];
int spfa(int s,int n)
{
	for(int i = 0;i<N;i++)
		dis[i] = 1e9 + 7;
	dis[s] = 0;
	queue<int> q;
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		if(cnt[u] > n)
			return -1;
		for(int i = 0;i<G[u].size();i++)
		{
			int v = G[u][i].first;
			int d = G[u][i].second;
			if(dis[v] > dis[u] + d)
			{
				dis[v] = dis[u] + d;
				if(!vis[v])
				{
					cnt[v] ++;
					q.push(v);
					vis[v] = 1;
				}

			}

		}
	}
	if(dis[n] >= 1e9 + 7)
		return - 2;
	else
		return dis[n];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		for(int i = 0;i<x;i++)
		{
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			add_edge(u,v,d);
		}
		for(int i = 0;i<y;i++)
		{
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			add_edge(v,u,-d);
		}
		for(int i = 1;i<n;i++)
			add_edge(i + 1,i , -1);
		printf("%d\n",spfa(1,n));
	}

}
