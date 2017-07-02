#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e5+5;

struct Edge
{
	int u,v,next;
}edge[N*2];
struct Tree
{
	int l,r,sum;
	int Max;
}t[N*4];
int sz[N],fa[N],top[N],bigson[N],deep[N];
int w[N];
int head[N];

int pos = 0;
int tot = 0;

void init()
{
	tot = 0;
	pos = 0;
	memset(sz,0,sizeof(sz));
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
	w[u] = ++ pos;
	if(bigson[u] !=-1)
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
	t[step].Max = max(t[step*2].Max,t[step*2+1].Max);
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r;
	t[step].sum = 0;
	t[step].Max = -INF;
	if(l == r)
		return;
	int mid = (l + r) / 2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
	push_up(step);
}
void update(int x,int val,int step)
{
	if(t[step].l == t[step].r)
	{
		t[step].Max = t[step].sum = val;
		return ;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if(x <= mid)
		update(x,val,step*2);
	else 
		update(x,val,step*2+1);
	push_up(step);
}
int query_sum(int l,int r,int step)
{
	if(t[step].l == l && t[step].r == r)
		return t[step].sum;
	int mid = (t[step].l + t[step].r) / 2;
	if(r <= mid)
		return query_sum(l,r,step*2);
	else if( l >  mid)
		return query_sum(l,r,step*2+1);
	else
		return query_sum(l,mid,step*2) + query_sum(mid+1,r,step*2+1);
}
int query_Max(int l,int r,int step)
{
	if(t[step].l == l && t[step].r == r)
		return t[step].Max;
	int mid = (t[step].l + t[step].r) / 2;
	if(r <= mid)
		return query_Max(l,r,step*2);
	else if(l > mid)
		return query_Max(l,r,step*2+1);
	else 
		return max(query_Max(l,mid,step*2),query_Max(mid+1,r,step*2+1));	
}
int get_sum(int x,int y)
{
	int sum = 0;
	while(top[x] != top[y])
	{
		if(deep[top[x]] < deep[top[y]])
			swap(x,y);
		sum += query_sum(w[top[x]],w[x],1);
		x = fa[top[x]];
	}
	if(deep[x] > deep[y])
		swap(x,y);
	sum += query_sum(w[x],w[y],1);
	return sum;
}
int get_Max(int x,int y)
{
	int ans = -INF;
	while(top[x] != top[y])
	{
		if(deep[top[x]] < deep[top[y]])
			swap(x,y);
		ans = max(ans,query_Max(w[top[x]],w[x],1));
		x = fa[top[x]];
	}
	if(deep[x] > deep[y])
		swap(x,y);
	ans = max(ans,query_Max(w[x],w[y],1));
	return ans;
}
void debug(int step)
{
	if(t[step].l == t[step].r)
	{
		printf("%d ",t[step].Max);
		return;
	}
	debug(step*2);
	debug(step*2+1);
}
int a[N];
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		init();
		for(int i = 1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,1,0);
		link(1,1);
		build(1,pos,1);
		for(int i = 1;i<=n;i++)
			scanf("%d",a+i);
		for(int i = 1;i<=n;i++)
			update(w[i],a[i],1);
		char op[10];
		int x,y;
		int q;
		scanf("%d",&q);
		for(int i = 0;i<q;i++)
		{
			scanf("%s%d%d",op,&x,&y);
			if(op[0] == 'Q')
			{
				if(op[1] == 'M')
					printf("%d\n",get_Max(x,y));
				else
					printf("%d\n",get_sum(x,y));
			}
			else
				update(w[x],y,1);
		}
	}	
}
