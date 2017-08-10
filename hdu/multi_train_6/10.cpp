#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3 + 7;
int dep[N];
struct Edge
{
	int u,v;
	bool operator < (const Edge & rhs) const
	{
		return max(dep[u],dep[v]) > max(dep[rhs.u],dep[rhs.v]);
	}
}edge[N*2];
vector<int>G[N];
int vis[N];
int tot = 0;
int n,k;
void init()
{
	memset(dep,0,sizeof(dep));
	for(int i = 0;i<1e3;i++)
		G[i].clear();
	tot = 0;
	memset(vis,0,sizeof(vis));
}
void add_edge(int u,int v)
{
	G[u].push_back(v);
	edge[tot++] = {u,v};
}
void dfs(int u,int d)
{
	dep[u] = d;
	for(auto v : G[u])
		dfs(v,d+1);
}
bool judge()
{
	for(int i = 1;i<=n;i++)
		if(!vis[i])
			return false;
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&k);
		for(int i = 2;i<=n;i++)
		{
			int f;
			scanf("%d",&f);
			add_edge(f,i);
		}
		for(int i = 1;i<=n;i++)
			if(!dep[i])
				dfs(i,0);
		sort(edge,edge+tot);
		for(int i = 0;i<tot;i++)
		{
			int u = edge[i].u , v = edge[i].v;			
			if((!vis[u]) && (!vis[v]))
			{
				k -- ;
				vis[u] = 1;
				vis[v] = 1;
			}
		}
		k++;
		if(judge())
		{
			if(k < 0)
				printf("Alice\n");
			else
				printf("Bob\n");	
		}
		else
			printf("Alice\n");
	}
}
