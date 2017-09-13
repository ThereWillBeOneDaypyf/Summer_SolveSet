#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 1;

vector<pair<int,int> > edges;
vector<int> G[N],g[N];
bool is_cut[N*2];
int dfn[N],low[N],L[N],R[N];
int Index = 0,id = 0;
int fa[N],f[N][21],dep[N];
int n;
void init()
{
	Index = 0, id = 0;
	memset(dfn,0,sizeof(dfn));
	memset(is_cut,0,sizeof(is_cut));
	for(int i = 0;i<N;i++)
		G[i].clear(),g[i].clear(),fa[i] = i;
	edges.clear();
}
void add_edge(int u,int v)
{
	edges.push_back(make_pair(u,v));
	G[u].push_back(edges.size() - 1);
	edges.push_back(make_pair(v,u));
	G[v].push_back(edges.size() - 1);
}
void tarjan(int u,int Fa)
{
	dfn[u] = low[u] = ++ Index;
	for(int i = 0;i != G[u].size();i ++)
	{
		int v = edges[G[u][i]].second;
		if(v == Fa)
			continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u] = min(low[v],low[u]);
			if(low[v] > dfn[u])
				is_cut[G[u][i]] = is_cut[G[u][i] ^ 1] = true;
		}	
		else low[u] = min(low[u],dfn[v]);
	}
}
int find(int x)
{
	if(x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int u,int v)
{
	u = find(u), v = find(v);
	if(u == v)
		return;
	if(dep[u] > dep[v])
		swap(u,v);
	fa[v] = u;
}
void Create_Graph()
{
	for(int i = 1;i<=n;i++)
		tarjan(i,i);	
	for(int i = 0;i<edges.size();i++)
	{
		int u = edges[i].first, v = edges[i].second;
		if(!is_cut[i])
			merge(u,v);
	}
	for(int i = 0;i<edges.size();i++)
	{
		int u = edges[i].first, v = edges[i].second;
		if(is_cut[i])
			g[find(u)].push_back(find(v));
	}
	for(int i = 1;i<=n;i++)
	{
		sort(g[i].begin(),g[i].end());
		g[i].erase(unique(g[i].begin(),g[i].end()),g[i].end());
	}
}
void dfs(int u,int Fa,int d)
{
	dep[u] = d,f[u][0] = Fa;
	for(int i = 1;i<=20;i++)
		f[u][i] = f[f[u][i-1]][i-1];
	L[u] = ++ id;
	for(int i = 0;i != g[u].size();i ++)
	{
		int v = g[u][i];
		if(v == Fa)
			continue;
		dfs(v,u,d+1);
	}
	R[u] = id;
}
int lca(int u,int v)
{
	if(dep[u] < dep[v])
		swap(u,v);
	for(int i = 20;i>=0;i--)
		if(dep[f[u][i]] >= dep[v])
			u = f[u][i];
	if(u == v)
		return u;
	for(int i = 20;i>=0;i--)
		if(f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}
struct Tree
{
	int vis,sum;
}t[N*4];
void push_down(int l,int r,int step)
{
	int mid = (l + r) / 2;
	if(!t[step].vis)
		return;
	t[step * 2].vis += t[step].vis;
	t[step * 2 + 1].vis += t[step].vis;
	t[step * 2].sum += t[step].vis * (mid - l + 1);
	t[step * 2 + 1].sum += t[step].vis * (r - (mid + 1) + 1);
	t[step].vis = 0;
}
void build()
{
	memset(t,0,sizeof(t));
}
void update(int l,int r,int ql,int qr,int val,int step)
{
	if(l == ql && r == qr)
	{
		t[step].vis += val;
		t[step].sum += (r - l + 1) * val;
		return;
	}
	int mid = (l + r) / 2;
	push_down(l,r,step);
	if(qr <= mid)
		update(l,mid,ql,qr,val,step*2);
	else if(ql > mid)
		update(mid + 1,r, ql,qr,val,step*2+1);
	else update(l,mid,ql,mid,val,step * 2),update(mid+1,r,mid+1,qr,val,step*2+1);
}
int query(int x,int l,int r,int step)
{
	if(l == r)
		return t[step].sum;
	int mid = (l + r) / 2;
	push_down(l,r,step);
	if(x <= mid)
		return query(x,l,mid,step*2);
	else return query(x,mid+1,r,step*2+1);
}
void link(int u,int v)
{
	u = find(u), v = find(v);
	int anc = find(lca(u,v));
	while(find(u) != find(anc))
	{
		update(1,n,L[find(u)],R[find(u)],-1,1);
		merge(find(u),f[find(u)][0]);
	}
	while(find(v) != find(anc))
	{
		update(1,n,L[find(v)],R[find(v)],-1,1);
		merge(find(v),f[find(v)][0]);
	}
}
int Get_Ans(int u,int v)
{
	u = find(u), v = find(v);
	int anc = find(lca(u,v));
	return query(L[u],1,n,1) + query(L[v],1,n,1) - 2 * query(L[anc],1,n,1);
}
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while(T--)
	{
		int m;
		init();
		scanf("%d%d",&n,&m);	
		for(int i = 0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		Create_Graph();
		build();
		dfs(find(1),find(1),0);
		for(int i = 1;i<=n;i++)
			if(find(i) == i)
				update(1,n,L[i],L[i],dep[i],1);
		int q;
		scanf("%d",&q);
		printf("Case #%d:\n",++ka);
		for(int i = 0;i<q;i++)
		{
			int op,x,y;
			scanf("%d%d%d",&op,&x,&y);
			if(op == 1)
				link(x,y);
			else printf("%d\n",Get_Ans(x,y));
		}
	}
}
