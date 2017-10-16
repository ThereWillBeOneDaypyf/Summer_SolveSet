#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 7;
struct Tree
{
	int l,r;
	int sum = 0;
}t[N*4];
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r;
	t[step].sum = 0;
	if(l == r)
		return;
	int mid = (l + r) / 2;
	build(l,mid,step*2); 
	build(mid + 1,r,step*2+1);
}
void push_up(int step)
{
	t[step].sum = t[step*2].sum + t[step*2+1].sum;
}
void update(int x,int step)
{
	if(t[step].l == t[step].r)
	{
		t[step].sum ++;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if(x <= mid)
		update(x,step*2);
	else
		update(x,step*2+1);
	push_up(step);
}
int query(int l,int r,int step)
{
	if(l == t[step].l && r == t[step].r)
		return t[step].sum;
	int mid = (t[step].l + t[step].r) / 2;
	if(r <= mid)
		return query(l,r,step*2);
	else if(l > mid)
		return query(l,r,step*2+1);
	else return query(l,mid,step*2) + query(mid+1,r,step*2+1);
}

int lt[N];
int vis[N];
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		memset(vis,0,sizeof(vis));
		printf("1");
		build(1,n,1);
		int pre = n;
		for(int i = 1;i <= n;i++)
		{
			int p;
			scanf("%d",&p);
			vis[p] = 1;
			update(p,1);
			while(vis[pre])
				pre --;
			int ans = i + 1 - query(max(1,pre),n,1);
			printf(" %d",ans);
		}
	}
}
