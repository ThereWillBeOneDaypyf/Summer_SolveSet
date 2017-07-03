#pragma comment(linker, "/STACK:1024000000,1024000000");
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

const int N = 1e5+7;

struct Edge
{
	int u,v,next;
	ll d;
}edge[N*2],e[N];

struct Tree
{
	int l,r;
	ll sum;
	ll vis;
}t[N*4];

int tot = 0;
int pos = 0;
int e_tot = 0;

int sz[N],fa[N],top[N],bigson[N],deep[N],w[N];
int head[N];

void init()
{
	e_tot = 0;
	tot = 0;
	pos = 0;
	memset(head,-1,sizeof(head));
}
void add_edge(int u,int v)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}

void dfs(int u,int Fa,int d)
{
	fa[u] = Fa;
	sz[u] = 1;
	deep[u] = d;
	bigson[u] = -1;
	for(int i = head[u];i!=-1;i=edge[i].next)
	{
		int v = edge[i].v;
		if(v == Fa)
			continue;
		dfs(v,u,d+1);
		sz[u] += sz[v];
		if(bigson[u] == -1 || sz[v] > sz[bigson[u]])
			bigson[u] = v;
	}
}
void link(int u,int tp)
{
	top[u] = tp;
	w[u] = ++pos;
	if(bigson[u] != -1)
		link(bigson[u],tp);
	for(int i = head[u];i!=-1;i=edge[i].next)
	{
		int v = edge[i].v;
		if(v == bigson[u] || v == fa[u])
			continue;
		link(v,v);
	}
}
void push_up(int step)
{
	t[step].sum = t[step*2].sum + t[step*2+1].sum;
}
void push_down(int step)
{
	if(!t[step].vis)
		return;
	t[step*2].vis = t[step].vis;
	t[step*2+1].vis = t[step].vis;
	t[step*2].sum = (t[step*2].r - t[step*2].l +1) * t[step].vis;
	t[step*2+1].sum = (t[step*2+1].r - t[step*2+1].l + 1) * t[step].vis;
	t[step].vis = 0;
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r,t[step].sum = 0,t[step].vis = 0;
	if(l == r)
		return;
	int mid = (l + r) / 2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
	push_up(step);
}
void update(int l,int r,ll val,int step)
{
	if(t[step].l == l && t[step].r == r)
	{
		t[step].sum = (t[step].r - t[step].l + 1) * val;
		t[step].vis = val;	
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if(r <= mid)
		update(l,r,val,step*2);
	else if(l > mid)
		update(l,r,val,step*2+1);
	else
		update(l,mid,val,step*2),update(mid+1,r,val,step*2+1);
	push_up(step);
}	
ll query(int l,int r,int step)
{
	if(t[step].l == l && t[step].r == r)
		return t[step].sum;
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if(r <= mid)
		return query(l,r,step*2);
	else if(l >  mid)
		return query(l,r,step*2+1);
	else return query(l,mid,step*2) + query(mid+1,r,step*2+1);
}
void change(int x,int y,ll val)
{
	while(top[x] != top[y])
	{
		if(deep[top[x]] < deep[top[y]])
			swap(x,y);
		update(w[top[x]],w[x],val,1);
		x = fa[top[x]];
	}
	if(deep[x] > deep[y])
		swap(x,y);
	update(w[x],w[y],val,1);
}
ll get_sum(int x,int y)
{
	ll sum = 0;
	while(top[x] != top[y])
	{
		if(deep[top[x]] < deep[top[y]])
			swap(x,y);
		sum += query(w[top[x]],w[x],1);
		x = fa[top[x]];	
	}
	if(x == y)
		return temp;
	if(deep[x] > deep[y])
		swap(x,y);
	sum += query(w[bigson[x]],w[y],1);
	return sum;	
}	
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2)
	{
		init();
		for(int i = 1;i<n;i++)
		{
			int u,v;
			ll d;
			scanf("%d%d%lld",&u,&v,&d);
			e[i].u = u;
			e[i].v = v;
			e[i].d = d;
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,1,0);
		link(1,1);
		build(1,n,1);
		update(w[1],w[1],0,1);
		for(int i = 1;i<n;i++)
		{
			int u = e[i].u;
			int v = e[i].v;
			ll d = e[i].d;
			if(deep[u] < deep[v])
				swap(u,v);
			change(u,u,d);
		}
		for(int i = 0;i<m;i++)
		{
			int op,x,y;
			scanf("%d%d%d",&op,&x,&y);
			if(!op)
			{
				int u = e[x].u;
				int v = e[x].v;
				if(deep[u] < deep[v])
					swap(u,v);
				change(u,u,y);
			}
			else
				printf("%lld\n",get_sum(x,y));
		}
	}
	return 0;
}
