#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5+7;

struct Tree
{
	int l,r,Max,Min;
	int vis;
}t[N*4];


int v[N];
void push_down(int step)
{
	t[step*2].Max = max(t[step*2].vis + t[step].Max,t[step*2].Max);
	t[step*2].Min = min(t[step*2].vis + t[step].Min,t[step*2].Min);
	t[step*2+1].Max = max(t[step*2+1].vis + t[step].Max,t[step*2+1].Max);
	t[step*2+1].Min = min(t[step*2+1].vis + t[step].Min,t[step*2+1].Min);
	t[step*2].vis += t[step].vis,t[step*2+1].vis += t[step].vis;
	t[step].vis = t[step].Max = t[step].Min = 0;
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r,t[step].vis = t[step].Max = t[step].Min = 0;
	if(l == r)
		return;
	int mid = (l + r) / 2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
}
void update(int l,int r,int val,int step)
{
	if(l == t[step].l && r == t[step].r)
	{
		t[step].vis += val;
		t[step].Max = max(t[step].Max,t[step].vis);
		t[step].Min = min(t[step].Min,t[step].vis);
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
}
int query(int x,int step)
{
	if(t[step].l == t[step].r)
		return max(abs(v[x]+t[step].Max),abs(v[x]+t[step].Min));
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if(x <= mid)
		return query(x,step*2);
	else
		return query(x,step*2+1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 1;i<=n;i++)
			scanf("%d",v+i);
		build(1,n,1);
		for(int i = 0;i<m;i++)
		{
			int op;
			int x,y,z;
			scanf("%d",&op);
			if(op == 1)
			{
				scanf("%d%d%d",&x,&y,&z);
				update(x,y,z,1);
			}
			else
			{
				scanf("%d",&x);
				printf("%d\n",query(x,1));
			}
		}
	}
}
