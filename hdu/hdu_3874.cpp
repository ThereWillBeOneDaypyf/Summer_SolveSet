#include<bits/stdc++.h>
using namespace std;



//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

struct Edge
{
	int u,v;
	int next;
}edge[N*2];
struct Tree
{
	int l,r;
	int task;
	int vis;
}t[N*4];
int head[N];
int L[N],R[N];
int tot = 0;
int Index = 0;
void init()
{
	memset(head,-1,sizeof(head));
	tot = 0;
	Index = 0;
}
void add_edge(int u,int v)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void dfs(int u)
{
	L[u] = ++Index;
	for(int i = head[u];i != -1; i =edge[i].next)
	{
		int v = edge[i].v;
		dfs(v);
	}
	R[u] = Index;
}
void push_down(int step)
{
	if(t[step].vis == -1)
		return;
	t[step*2].task = t[step*2+1].task = t[step*2].vis = t[step*2+1].vis = t[step].task;
	t[step].vis = -1;
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r;
	t[step].task = -1,t[step].vis = -1;
	if(l == r)
		return;
	int mid = (l + r)/2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
}
void update(int l,int r,int val, int step)
{
	if(t[step].l == l && t[step].r == r)
	{
		t[step].task = val;
		t[step].vis = val;
		return;
	}
	push_down(step);
	int mid = (t[step].l + t[step].r) /2;
	if(r <= mid)
		update(l,r,val,step*2);
	else if(l > mid)
		update(l,r,val,step*2+1);
	else
		update(l,mid,val,step*2),update(mid+1,r,val,step*2+1);
}
int query(int x,int step)
{
	if(t[step].l == t[step].r)
		return t[step].task;
	push_down(step);
	int mid = (t[step].l + t[step].r) / 2;
	if(x <= mid)
		return query(x,step*2);
	else
		return query(x,step*2+1);
}
int deg[N];
int main()
{
	int T;
	scanf("%d",&T);
	int ka = 0;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		init();
		memset(deg,0,sizeof(deg));
		for(int i = 1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(v,u);
			deg[u] ++;
		}
		for(int i = 1; i<= n;i++)
		{
			if(!deg[i])
				dfs(i);
		}
		int m;
		scanf("%d",&m);
		build(1,Index+1,1);
		printf("Case #%d:\n",++ka);
		for(int i =0;i<m;i++)
		{
			char op[5];
			int x,y;
			scanf("%s%d",op,&x);
			if(op[0] == 'C')
				printf("%d\n",query(L[x],1));
			else
			{
				scanf("%d",&y);
				update(L[x],R[x],y,1);
			}
		}
	}
	return 0;
}
