#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7 + 1e5;
const long long INF = 1e18;

vector<pair<int,long long> >G[N  * 2];
long long dis[N * 2][2];
bool vis[N * 2];
void init()
{
	for(int i = 0;i<N * 2;i++)
		G[i].clear();
}
void add_edge(int u,int v,long long d)
{
	G[u].push_back(make_pair(v,d));
}
void spfa(int s,int n,int flag)
{
	for(int i = 1;i<=n;i++)
		dis[i][flag] = INF;
	dis[s][flag] = 0;
	vis[s] = 1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = 0;i<G[u].size();i++)
		{
			int v = G[u][i].first;
			long long d = G[u][i].second;
			if(dis[v][flag] > dis[u][flag] + d)
			{
				dis[v][flag] = dis[u][flag] + d;
				if(!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	int ka = 0;
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		init();
		for(int i = 1;i<=m;i++)
		{
			int cnt;
			long long t;
			scanf("%lld%d",&t,&cnt);
			add_edge(n + i,n + m + i,t);
			for(int j = 0;j<cnt;j++)
			{
				int v;
				scanf("%d",&v);
				add_edge(v,n + i,0);
				add_edge(n + m + i,v,0);
			}
		}
		spfa(1,n + m * 2,0);
		spfa(n,n + m * 2,1);
		long long ans = INF;
		for(int i = 1;i<=n;i++)
			ans = min(ans,max(dis[i][0],dis[i][1]));		
		printf("Case #%d: ", ++ ka);
		if(ans >= INF)
			printf("Evil John\n");
		else
		{
			printf("%lld\n",ans);
			int all = 0;
			for(int i = 1;i<=n;i++)
			{
				if(max(dis[i][0],dis[i][1]) == ans)
				{
					if(all)
						printf(" ");
					printf("%d",i);
					all ++;
				}
			}
			printf("\n");
		}
	}
}
