#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

int sz[N],fa[N],deep[N],w[N],head[N],bigson[N],top[N];
int tot = 0,Index;

struct Edge
{
	int u,v;
	int next;
}edge[N*2];
struct Tree
{
	int l,r;
	int sum;
	int vis;
}t[N*4];
void init()
{
	tot = 0;
	Index = 0;
	memset(head,-1,sizeof(head));
	memset(bigson,0,sizeof(bigson));
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
	sz[u] = 1;
	deep[u] = d;
	fa[u] = Fa;
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
	w[u] = ++ Index;
	if(bigson[u]!=-1)
		link(bigson[u],tp);
	for(int i = head[u];i!=-1;i=edge[i].next)
	{
		int  v = edge[i].v;
		if(v == bigson[u] || fa[u] == v)
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
	t[step*2].vis += t[step].vis;
	t[step*2+1].vis += t[step].vis;
	t[step*2].sum += t[step].vis * (t[step*2].r - t[step*2].l + 1);
	t[step*2+1].sum += t[step].vis * (t[step*2+1].r - t[step*2+1].l + 1);
	t[step].vis = 0;
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r,t[step].sum = 0;
	t[step].vis = 0;
	if(l == r)
		return;
	int mid = (l + r)/2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
}
void update(int l,int r,int val,int step)
{
	if(t[step].l == l && t[step].r == r)
	{
		t[step].vis += val;
		t[step].sum += val * (t[step].r - t[step].l + 1);
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if(r<=mid)
		update(l,r,val,step*2);
	else if(l > mid)
		update(l,r,val,step*2+1);
	else
		update(l,mid,val,step*2),update(mid+1,r,val,step*2+1);
	push_up(step);
}
int query(int x,int step)
{
	if(t[step].l == t[step].r)
		return t[step].sum;
	push_down(step);
	int mid = (t[step].l + t[step].r) / 2;
	if(x <= mid)
		return query(x,step*2);
	else return query(x,step*2+1);
}
void change(int x,int y,int val)
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
int a[N];
int main()
{
	 int n,m,q;
	 while(scanf("%d%d%d",&n,&m,&q)==3)
	 {
		init();	
		for(int i = 1;i<=n;i++)
			scanf("%d",a+i);
		for(int i = 0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,-1,1);
		link(1,1);
		build(1,Index,1);
		for(int i = 1;i<=n;i++)
			update(w[i],w[i],a[i],1);
		for(int i = 0;i<q;i++)
		{
			char op[5];
			scanf("%s",op);
			if(op[0] == 'Q')
			{
				int x;
				scanf("%d",&x);
				printf("%d\n",query(w[x],1));	
			}
			else if(op[0] == 'I')
			{
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				change(x,y,z);
			}
			else
			{
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				change(x,y,-z);
			}
		}
	 }
	 return 0;
}
