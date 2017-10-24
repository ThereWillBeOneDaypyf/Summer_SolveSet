#include<bits/stdc++.h>
using namespace std;

const int N = 2e4;

vector<int> G[N];
int clr[N];
int deg[N];
int vis[N];
void init()
{
	for(int i = 0;i<N;i++)
		G[i].clear();
	memset(vis,0,sizeof(vis));
	memset(clr,-1,sizeof(clr));
	memset(deg,0,sizeof(deg));
}
bool dfs(int u,int fa,int flag)
{
	if(clr[u] == -1)
		clr[u] = flag;
	else if(clr[u] != flag)
		return false;
	if(vis[u])
		return true;
	vis[u] = 1;
	for(auto v : G[u])
	{
		if(!dfs(v,u,flag ^ 1))
			return false;
	}
	return true;
}
int main()
{
	int n,m,x,y;
	while(scanf("%d%d%d%d",&n,&m,&x,&y) == 4)
	{
		init();
		for(int i = 0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			deg[u] ++;
			deg[v] ++;
		}
		for(int i = 0;i<x;i++)
		{
			int x;
			scanf("%d",&x);
			clr[x] = 0;
		}
		for(int i = 0;i<y;i++)
		{
			int x;
			scanf("%d",&x);
			clr[x] = 1;
		}
		int flag = 1;
		for(int i = 1;i<=n;i++)
			if(!deg[i] && clr[i] == -1)
				flag = 0;
		if(!x && !y)
		{
			for(int i = 1;i<=n;i++)
				if(clr[i] == -1)
					if(!dfs(i,i,0))
						flag = 0;
		}
		else
		{
			for(int i = 1;i<=n;i++)
			{
				if(!vis[i] && clr[i] != -1)
				{
					if(!dfs(i,i,clr[i]))
						flag = 0;
				}
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
