#include<bits/stdc++.h>

using namespace std;


//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

const int N = 1e5 + 7;

struct Edge
{
	int u,v,next;
	ll d;
}edge[N*2];
struct Query
{
	int id;
	int u,v;
	int next;
}Q[N*2];


int fa[N];
int vis[N];
int ans[N];
int head[N];
ll dis[N];
int q_head[N];
int tot = 0;
int q_tot = 0;

void init()
{
	memset(Q,0,sizeof(Q));
	memset(edge,0,sizeof(edge));
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
	memset(q_head,-1,sizeof(q_head));
	memset(dis,0,sizeof(dis));
	tot = 0;
	q_tot = 0;
}
void add_edge(int u,int v, ll d)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].d = d;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void add_q(int u,int v,int id)
{
	Q[q_tot].u = u;
	Q[q_tot].v = v;
	Q[q_tot].id = id;
	Q[q_tot].next = q_head[q_tot];
	q_head[u] = q_tot ++ ; 
}
int find(int x)
{
	if(x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void get_inf(int u,int Fa)
{
	for(int i = head[u] ;i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if(v == Fa)
			continue;
		dis[v] = dis[u] + edge[i].d;
		get_inf(v,u);
	}
}
void lca(int u,int Fa)
{
	fa[u] = u;
	for(int i = head[u];i!=-1;i=edge[i].next)
	{
		int v= edge[i].v;
		if(v == Fa)
			continue;
		lca(v,u);
		fa[v] = u;
	}
	vis[u] = 1;
	for(int i = q_head[u];i!=-1;i=Q[i].next)
	{
		int v= Q[i].v;
		if(vis[v])
		{
			ans[Q[i].id] = find(v);
		}
	}
}
ll get_dis(int u,int v,int id)
{
	return dis[u] + dis[v] - 2 * dis[ans[id]];
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
		vector<pair<int,int> > query;
		query.clear();
		for(int i = 1;i < n;i++)
		{
			int u,v;
			ll d;
			scanf("%d%d%lld",&u,&v,&d);
			add_edge(u,v,d);
			add_edge(v,u,d);
		}
		get_inf(1,1);
		for(int i = 0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_q(u,v,i);
			add_q(v,u,i);
			query.push_back(make_pair(u,v));
		}
		lca(1,1);
		for(int i = 0;i<m;i++)
		{
			int u = query[i].first;
		   	int v = query[i].second;
			printf("%lld\n",get_dis(u,v,i));
		}	
	}	
}
