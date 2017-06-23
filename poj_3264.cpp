#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e5 +5;

struct Tree
{
	int l,r;
	int Max,Min;
}t[N*4];
struct ANS
{
	int Max,Min;
};
void push_up(int step)
{
	t[step].Min = min(t[step*2].Min,t[step*2+1].Min);
	t[step].Max = max(t[step*2].Max,t[step*2+1].Max);
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r;
	t[step].Max = 0,t[step].Min = INF;
	if(l == r)
	{
		scanf("%d",&t[step].Min);
		t[step].Max = t[step].Min;
		return;
	}
	int mid = (t[step].l + t[step].r)/2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
	push_up(step);
}
ANS query(int l,int r,int step)
{
	if(l == t[step].l && r == t[step].r)
	{	
		ANS ans = {t[step].Max,t[step].Min};
		return 	ans;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if( r <= mid )
		return query(l,r,step*2);
	else if( l > mid)
		return query(l,r,step*2+1);
	else
	{
		ANS temp1 = query(l,mid,step*2),temp2 = query(mid+1,r,step*2+1);
		ANS ans = {max(temp1.Max,temp2.Max),min(temp1.Min,temp2.Min)};
		return ans;
	}
}
int main()
{
	int n,q;
	while(scanf("%d%d",&n,&q)==2)
	{
		build(1,n,1);
		for(int i = 0 ; i < q ; i ++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			ANS ans = query(l,r,1);
			printf("%d\n",ans.Max - ans.Min);
		}
	}
	return 0;
}
