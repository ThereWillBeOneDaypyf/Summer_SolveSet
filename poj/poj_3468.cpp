#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

const int N = 1e5+5;

struct Tree
{
	int l,r,step;
	ll sum;
	ll vis;
}t[N*4];

void push_up(int step)
{
	t[step].sum = t[step*2+1].sum + t[step*2].sum;
}
void push_down(int step)
{
	if(!t[step].vis)
		return;
	t[step*2].vis += t[step].vis;
	t[step*2+1].vis += t[step].vis;
	t[step*2].sum += (t[step*2].r - t[step*2].l + 1) * t[step].vis;
	t[step*2+1].sum += (t[step*2+1].r - t[step*2+1].l + 1) * t[step].vis;
	t[step].vis = 0;
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r =r;
	t[step].sum = 0,t[step].vis = 0;
	if( l == r)
	{
		scanf("%lld",&t[step].sum);
		return ;
	}
	int mid = (l + r ) /2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
	push_up(step);
}
void update(int l,int r,ll val,int step)
{
	if(l == t[step].l && t[step].r == r)
	{
		t[step].vis += val;
		t[step].sum += (r - l + 1) * val;
		return;
	}
	push_down(step);
	int mid = (t[step].l + t[step].r)/2;
	if( r<= mid )
		update(l , r,val ,step*2);
	else if( l > mid)
		update(l , r ,val ,step*2+1);
	else
		update(l,mid,val,step*2) , update(mid+1,r,val,step*2+1);
	push_up(step);
}
ll query(int l,int r,int step)
{
	if(l==t[step].l && t[step].r == r)
		return t[step].sum;
	push_down(step);
	int mid = (t[step].l + t[step].r)/2;
	if( r <= mid)
		return query(l,r,step*2);
	else if( l > mid)
		return query(l,r,step*2+1);
	else
		return query(l,mid,step*2) + query(mid+1,r,step*2+1);
}

int main()
{
	int n,q;
	while(scanf("%d%d",&n,&q)==2)
	{
		build(1,n,1);
		for(int i = 0;i< q; i++)
		{
			char op[5];
			ll x,y,z;
			scanf("%s%lld%lld",op,&x,&y);
			if(op[0] == 'C')
			{
				scanf("%lld",&z);
				update(x,y,z,1);
			}
			else
				printf("%lld\n",query(x,y,1));
		}
	}
	return 0;
}
