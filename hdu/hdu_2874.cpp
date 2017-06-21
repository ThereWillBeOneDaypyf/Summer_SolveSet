#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 10001;
struct Edge
{
	int v;
	int d;
	int next;
}edge[20001];
struct Query
{
	int v,next;
	int id;
}Q[2000001];
int tot = 0;
int q_tot = 0;
int head[N];
int qhead[N];
int vis[N];
int ans[1000001];
int fa[N];
int dis[N];
void init(int n)
{
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	memset(qhead,-1,sizeof(qhead));
	tot = 0;
	q_tot = 0;
}
int find(int x)
{
	if(fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void add_edge(int u,int v,int d)
{
	edge[tot] = {v, d, head[u]};
	head[u] = tot++;
}
void add_Q(int u,int v,int id)
{
	Q[q_tot] = {v, qhead[u], id};
	qhead[u] = q_tot ++;
}
void lca(int u,int Fa)
{
	vis[u] = 1;
	fa[u] = u;
	int i, v;
	for(i = head[u];i!=-1;i=edge[i].next)
	{
		v = edge[i].v;
		if(v == Fa)
			continue;
		dis[v] = dis[u] + edge[i].d;
		lca(v,u);
		fa[v] = u;
	}
	for(i = qhead[u];i!=-1;i=Q[i].next)
	{
		v = Q[i].v;
		if (v == Fa) continue;
		if(vis[v])
		{
			int anc = find(v);
			if (dis[v] != -1)
				ans[Q[i].id] = dis[u] + dis[v] - 2 * dis[anc];
			else
				ans[Q[i].id] = -1;
		}
	}

}
void solve_lca(int n)
{
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i])
		{
			memset(dis, -1, sizeof(dis));
			lca(i,i);
		}
	}
}
int main()
{
	int n,m,q;
	int i, u, v, d;
	while(scanf("%d%d%d",&n,&m,&q)!=EOF)
	{
		init(n);
		for(i =0 ;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&d);
			add_edge(u,v,d);
			add_edge(v,u,d);
		}
		for(i =0 ;i<q;i++)
		{
			scanf("%d%d",&u,&v);
			add_Q(u,v,i);
			add_Q(v,u,i);
		}
		solve_lca(n); 
		for(i =0;i<q;i++)
		{
			if(ans[i] == -1)
				printf("Not connected\n");
			else
				printf("%d\n",ans[i]);
		}
	}	
	return 0;
}

