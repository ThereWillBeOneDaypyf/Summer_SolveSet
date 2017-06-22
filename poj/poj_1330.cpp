#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e5;

struct Edge
{
	int u,v,next;
}edge[N*2];
struct Query
{
	int u,v,next;
	int id;
}Q[N*2];

int head[N];
int qhead[N];
int qtot = 0;
int tot = 0;
int ans[N];
int vis[N];
int fa[N];

void init()
{
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	memset(qhead,-1,sizeof(qhead));
	qtot = 0;
	tot = 0;
}
void add_edge(int u,int v)
{
	edge[tot] = {u,v,head[u]};
	head[u] = tot ++;
}
void add_Q(int u,int v,int id)
{
	Q[qtot] = {u,v,qhead[u],id};
	qhead[u] = qtot ++;
}
int find(int x)
{
	if(fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void lca(int u,int Fa)
{
	vis[u] = 1;
	fa[u] = u;
	for(int i = head[u] ; i !=  -1;i = edge[i].next)
	{
		int v = edge[i].v;
		if(v == Fa)
			continue;
		lca(v,u);
		fa[v] = u;
	}
	for(int i = qhead[u] ;i!=-1;i = Q[i].next)
	{
		int v = Q[i].v;
		if(vis[v])
		{
			ans[Q[i].id] = find(v);
		}
	}

}
int deg[N];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		init();
		memset(deg,0,sizeof(deg));
		scanf("%d",&n);
		for(int i =1;i<n;i++)
		{
			int u ,v;
			scanf("%d%d",&u,&v);
			deg[v] ++;
			add_edge(u,v);
		}
		int u,v;
		scanf("%d%d",&u,&v);
		add_Q(u,v,0);
		add_Q(v,u,0);
		for(int i = 1; i<=n;i++)
		{
			if(!deg[i])
			{
				lca(i,i);
			}
		}
		printf("%d\n",ans[0]);
	}
}
