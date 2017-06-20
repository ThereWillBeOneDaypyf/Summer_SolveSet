#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 500005;

struct Tree
{
	int l,r;
	int step;
	int sum;
}t[N*4];
void push_up(int step)
{
	t[step].sum = t[step*2].sum + t[step*2+1].sum;
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r;
	t[step].sum = 0;
	if(l == r)
	{
		scanf("%d",&t[step].sum);
		return;
	}
	int mid = (l + r)/2;
	build(l , mid, step*2);
	build(mid + 1,r ,step*2+1);
	push_up(step);
}
void update(int x,int val,int step)
{
	if(t[step].l == t[step].r)
	{
		t[step].sum += val;
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
		return t[step].sum;
	int mid = (t[step].r + t[step].l) /2;
	if(r<=mid)
		return query(l,r,step*2);
	else if(l > mid)
		return query(l,r,step*2+1);
	else return query(l,mid,step*2) + query(mid+1,r,step*2+1);
}
int main()
{
	int T;
	scanf("%d",&T);
	int ka = 0;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		build(1,n,1);
		char op[10];
		printf("Case %d:\n", ++ ka );	
		while(scanf("%s",op)==1)
		{
			if(op[0] == 'E')
				break;
			int x,y;
			scanf("%d%d",&x,&y);
			if(op[0] == 'A')
				update(x,y,1);
			else if(op[0] == 'S')
				update(x,-y,1);
			else 
				printf("%d\n",query(x,y,1));
				
		}
	}
	return 0;
}
