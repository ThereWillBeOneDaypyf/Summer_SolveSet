#include<bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 7;

struct Tree
{
	int l,r;
	int gcd;
}t[N * 4];

void push_up(int step)
{
	t[step].gcd = __gcd(t[step * 2].gcd, t[step * 2 + 1].gcd);
}
void build(int l,int r,int step)
{
	t[step].l = l, t[step].r = r;
	t[step].gcd = 0;
	if(l == r)
	{
		scanf("%d",&t[step].gcd);
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,step * 2);
	build(mid + 1, r, step * 2 + 1);
	push_up(step);
}
void update(int x,int val,int step)
{
	if(t[step].l == t[step].r)
	{
		t[step].gcd = val;
		return;
	}
	int mid = (t[step].l + t[step].r) / 2;
	if(x <= mid)
		update(x,val,step * 2);
	else
		update(x,val,step * 2 + 1);
	push_up(step);
}
int query(int l,int r,int tar,int step)
{
	int mid = (t[step].l + t[step].r) / 2;
	if(t[step].l == l && r == t[step].r)
	{
		if(t[step].gcd % tar == 0)
			return 0;
		else if(t[step].l == t[step].r)
			return 1;
		else
		{
			int lsum = query(l,mid,tar,step * 2);
			int rsum = query(mid + 1,r,tar,step * 2 + 1);
			if(lsum == -1 || rsum == -1)
				return -1;
			else if(lsum + rsum > 1)
				return -1;
			return lsum + rsum;
		}
	}
	if(r <= mid)
		return query(l, r, tar, step * 2);
	else if(l > mid)
		return query(l, r, tar, step * 2 + 1);
	else
	{
		int lsum = query(l, mid, tar, step * 2);
		if(lsum == -1)
			return -1;
		int rsum = query(mid + 1, r, tar, step * 2 + 1);
        if(rsum == -1)
            return -1;
		if(lsum + rsum > 1)
			return -1;
		return lsum + rsum;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		build(1,n,1);
		int q;
		scanf("%d",&q);
		for(int i = 0;i < q;i++)
		{
			int op,l,r;
			scanf("%d%d%d",&op,&l,&r);
			if(op == 1)
			{
				int tar;
				scanf("%d",&tar);
				int flag = query(l,r,tar,1);
				if(flag != -1 && flag < 2)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
				update(l,r,1);
		}
	}
}