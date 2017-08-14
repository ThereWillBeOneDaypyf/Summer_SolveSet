#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 5e5 + 7;

vector<pair<int,int> >G[N];
long long dis[N];
int fa[N][21],dep[N];
void init()
{
	for(int i = 0;i<N;i++)
		G[i].clear();
}
void add_edge(int u,int v,int d)
{
	G[u].push_back(make_pair(v,d));
	G[v].push_back(make_pair(u,d));
}
void dfs(int u,int Fa,int d,long long w)
{
	fa[u][0] = Fa;
	dep[u] = d, dis[u] = w;
	for(int i = 1;i<21;i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];	
	for(auto temp : G[u])
	{
		int v = temp.first;
		int dd = temp.second;
		if(v == Fa)
			continue;
		dfs(v,u,d+1,w + dd);
	}
}
int lca(int u,int v)
{
	if(dep[u] < dep[v])
		swap(u,v);
	for(int i = 20;i>=0;i--)
		if(dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if(u == v)
		return u;
	for(int i = 20 ;i>=0;i--)
		if(fa[u][i] != fa[v][i])
			u = fa[u][i],v = fa[v][i];
	return fa[u][0];
}
/* qq ac */
struct ROAD{int u,v,anc;};
struct Tree
{
	int l,r;
	ROAD p;
}t[N*5];
int LCA[4];
bool cmp(int u,int v){ return dep[u] > dep[v];}
long long Get_dis(ROAD x)
{
	return dis[x.u] + dis[x.v] - 2 * dis[x.anc];
}
ROAD merge(ROAD x, ROAD y)
{
	LCA[0] = lca(x.u,y.u),LCA[1] = lca(x.u,y.v);	
	LCA[2] = lca(x.v,y.u),LCA[3] = lca(x.v,y.v); 
	sort(LCA,LCA+4,cmp);
	ROAD temp = {LCA[0],LCA[1],lca(LCA[0],LCA[1])};
	return temp;
}
void push_up(int step)
{
	t[step].p = merge(t[step << 1].p, t[step << 1 | 1].p);
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r;
	if(l == r)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		t[step].p = (ROAD){u, v, lca(u, v)};
		cout << u << " " << v << " " << lca(u, v)  << endl;
		return ;
	}
	int mid = (l + r) / 2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
	push_up(step);
}
ROAD query(int l,int r,int step)
{
	if(l == t[step].l && r == t[step].r)
		return t[step].p;
	int mid = (t[step].l + t[step].r) / 2;
	if(r <= mid)
		return query(l,r,step*2);
	else if(l > mid)
		return query(l,r,step*2+1);
	else
		return merge(query(l,mid,step*2),query(mid+1,r,step*2+1));
}
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		init();
		for(int i =1 ;i<n;i++)
		{
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			add_edge(u,v,d);
		}
		dfs(1,1,0,0);
		int m;
		scanf("%d",&m);
		build(1,m,1);
		int q;
		scanf("%d",&q);
		for(int i = 0;i<q;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%lld\n",Get_dis(query(u,v,1)));
		}
	}
}
