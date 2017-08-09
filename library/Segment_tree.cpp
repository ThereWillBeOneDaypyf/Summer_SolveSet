#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Tree
{
	int l,r,sum;
	int vis;
}t[N*4];

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
	t[step].l = l,t[step].r = r,t[step].sum = t[step].vis = 0;
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
		t[step].sum += (r - l + 1) * val;
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
	if(l == t[step].l && r == t[step].r)
		return t[step].sum;
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if(r <= mid)
		return query(l,r,step*2);
	else if(l > mid)
		return query(l,r,step*2+1);
	else
		return query(l,mid,step*2) + query(mid+1,r,step*2+1);
}
int main()
{
	return 0;
}
