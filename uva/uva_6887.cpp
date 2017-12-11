#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int N = 1e5 + 7;
vector<int> G[N];
int n,m;
int pre[N],vis[N];
void init()
{
	for(int i = 0;i<N;i++)
		G[i].clear();
}
void add_edge(int u,int v)
{
	G[u].push_back(v);
}
bool dfs(int u)
{
	for(int i = 0;i < G[u].size();i++)
	{
		int v = G[u][i];
		if(!vis[v])
		{
			vis[v] = 1;
			if(pre[v] == -1 || dfs(pre[v]))
			{
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
bool solve()
{
	memset(pre,-1,sizeof(pre));
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			ans ++;
	}
	return ans == n;
}
int main()
{
	while(scanf("%d%d",&n,&m) == 2)
	{
		init();
		for(int i = 0;i < m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		if(solve())
			printf("YES\n");
		else
			printf("NO\n");
	}
}
