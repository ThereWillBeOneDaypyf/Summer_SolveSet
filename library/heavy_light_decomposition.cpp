#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5+7;

struct Edge
{
	int u,v,next;
}edge[N*2];

struct Tree
{
	int l,r,sum;
	int vis;
}t[N*4];

int tot = 0;
int pos = 0;

int sz[N],fa[N],top[N],bigson[N],deep[N],w[N];
int head[N];

void init()
{
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
void update(int l,int r,int val,int step)
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
int query(int l,int r,int step)
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
int get_sum(int x,int y)
{
	int sum = 0;
	while(top[x] != top[y])
	{
		if(deep[top[x]] < deep[top[y]])
			swap(x,y);
		sum += query(w[top[x]],w[x],1);
		x = fa[top[x]];	
	}
	if(deep[x] > deep[y]) // point to point
		swap(x,y);
	sum += query(w[x],w[y],1);
	/*edge to point
	if(x == y)
		return sum;
	if(deep[x] > deep[y])
		swap(x,y);
	sum += query(w[bigson[x]],w[y],1);
	*/
	return sum;	
}	
int main()
{
}
