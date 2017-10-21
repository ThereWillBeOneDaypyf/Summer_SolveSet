#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 4e4 + 7;

long long dis[N];
int dep[N*4];
int dp[N*4][22];
int rec[N*4];
int first[N];
int LOG2[N*4];
int tot = 0;
vector<pair<int,int> > G[N];
void init()
{
	for(int i = 0; i< N;i++)
		G[i].clear();
	for(int i = 0;i<4*N;i++)
		LOG2[i] = (i == 0 ? -1 : LOG2[i>>1] + 1);
	tot = 0;
}
void add_edge(int u,int v,int d)
{
	G[u].push_back(make_pair(v,d));
	G[v].push_back(make_pair(u,d));
}
void dfs(int u,int fa,int d,long long w)
{
	dis[u] = w;
	first[u] = ++ tot;
	rec[tot] = u;
	dep[tot] = d;
	for(int i = 0;i != G[u].size();i++)
	{
		int v = G[u][i].first;
		int dd = G[u][i].second;
		if(v == fa)
			continue;
		dfs(v,u,d+1,w + dd);
		rec[++ tot] = u;
		dep[tot] = d;
	}
}
void init_st()
{
	for(int i = 1;i<=tot;i++)
		dp[i][0] = i;
	for(int j = 1;(1 << j)<= tot;j++)
	{
		for(int i = 1;i + (1 << j) <= tot + 1;i++)
		{
			int a = dp[i][j-1],b = dp[i + (1 << j -1)][j-1];
			dp[i][j] = dep[a] < dep[b] ? a : b;
		}
	}
}
int rmq(int l,int r)
{
	int k = LOG2[r - l + 1];
	int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
	return dep[a] < dep[b] ? a : b;
}

int lca(int u,int v)
{
	int x = first[u], y = first[v];
	if(x > y)
		swap(x,y);
	int res = rmq(x,y);
	return rec[res];
}
void debug()
{
	for(int i = 1;i<=tot;i++)
		cout << i << " ";
	cout << endl;
	for(int i = 1;i<=tot;i++)
		cout << rec[i] << " ";
	cout << endl;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		init();
		for(int i = 1;i<n;i++)
		{
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			add_edge(u,v,d);
		}	
		dfs(1,1,0,0);
		init_st();
		//debug();
		for(int i = 0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			int anc = lca(u,v);
			printf("%lld\n",dis[u] + dis[v] - 2 * dis[anc]);
		}
	}	
}
