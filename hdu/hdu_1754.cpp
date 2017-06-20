#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 200005;

struct Tree
{
	int l,r;
	int Max;
	int step;
}t[N*4];

void push_up(int step)
{
	t[step].Max = max(t[step*2].Max ,t[step*2+1].Max);
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r;
	t[step].Max = 0;
	if(l == r)
	{
		scanf("%d",&t[step].Max);
		return ;
	}
	int mid = (l + r)/2;
	build(l,mid,step*2);
	build(mid+ 1,r,step*2+1);
	push_up(step);
}
void update(int x,int val,int step)
{
	if(t[step].l == t[step].r)
	{
		t[step].Max = val;
		return;
	}
	int mid = (t[step].l + t[step].r) /2;
	if(x <= mid)
		update(x,val,step*2);
	else
		update(x,val,step*2+1);
	push_up(step);
}
int query(int l,int r,int step)
{
	if(t[step].l == l && t[step].r == r)
		return t[step].Max;
	int mid = (t[step].l + t[step].r)/2;
	if(r <= mid)
		return query(l,r,step*2);
	else if(l > mid)
		return query(l,r,step*2+1);
	else
		return max(query(l,mid,step*2),query(mid+1,r,step*2+1));
}
int main()
{
	int n,q;
	while(scanf("%d%d",&n,&q)==2)
	{
		build(1,n,1);
		for(int i =1;i<=q;i++)
		{
			char op[5];
			int x,y;
			scanf("%s%d%d",op,&x,&y);
			if(op[0] == 'Q')
				printf("%d\n",query(x,y,1));
			else
				update(x,y,1);
		}
	}
}
