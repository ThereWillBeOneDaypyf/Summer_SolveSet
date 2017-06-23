#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

struct Tree
{
	int l,r;
	int sum;
}t[N*8];

int ans[N*2];

void push_up(int step)
{
	t[step].sum = t[step*2].sum + t[step*2+1].sum;
}

void build(int l,int r,int step)
{
	t[step].l = l , t[step].r = r;
	t[step].sum = r - l + 1;
	if(l == r)
		return;
	int mid = (l + r) / 2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
}
void update(int pos,int val,int step)
{
	if(t[step].l == t[step].r)
	{
		t[step].sum = 0;
		ans[t[step].l] = val;
		return;
	}
	if(t[step*2].sum >= pos)
		update(pos,val,step*2);
	else
		update(pos-t[step*2].sum,val,step*2+1);
	push_up(step);	
}
void debug(int step)
{
	if(t[step].l == t[step].r)
	{
		cout << t[step].sum <<" ";
		return;
	}
	debug(step*2);
	debug(step*2+1);
}
struct Node
{
	int pos,val;
}a[N*2];
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		for(int i =0; i< n;i++)
		{
			scanf("%d%d",&a[i].pos,&a[i].val);
			a[i].pos ++;
		}	
		build(1,n,1);
		for(int i = n - 1;i >= 0 ; i --)
		{
			update(a[i].pos,a[i].val,1);
		}
		for(int i = 1;i<=n;i++)
			i == n ? printf("%d\n",ans[i]) : printf("%d ",ans[i]);
	}
	return 0;
}
