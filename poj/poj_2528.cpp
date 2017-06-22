#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<map>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e5 +5;

struct Tree
{
	int l,r;
	int vis;
}t[N*4];

void push_down(int step)
{
	if(!t[step].vis)
		return;
	t[step*2].vis = t[step*2+1].vis = t[step].vis;
	t[step].vis = 0;
}

void build(int l,int r,int step)
{
	t[step].l = l;
	t[step].r = r;
	t[step].vis = 0;
	if(l == r)
		return;
	int mid = (l + r)/2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
}
void update(int l,int r,int val,int step)
{
	if(l == t[step].l && r == t[step].r)
	{
		t[step].vis = val;
		return;
	}
	int mid = (t[step].l + t[step].r)/2;
	push_down(step);
	if(r <= mid)
		update(l,r,val,step*2);
	else if( l > mid)
		update(l,r,val,step*2+1);
	else
		update(l,mid,val,step*2) , update(mid + 1,r,val,step*2+1);
}
int query(int x,int step)
{
	if( x >= t[step].l && x <= t[step].r && t[step].vis)
		return t[step].vis;
	if( t[step].l == t[step].r)
		return 0;
	push_down(step);
	int mid = (t[step].l + t[step].r)/2;
	if( x <= mid)
		return query(x,step*2);
	else
		return query(x,step*2+1);
}
int l[N],r[N];
int all[N*2];
int get_id(int tar,int cnt)
{
	return lower_bound(all + 1,all + 1 + cnt ,tar) - all ;
}
void debug(int step)
{
	if(t[step].l == t[step].r)
	{
		cout << t[step].vis << " ";
		return;
	}
	push_down(step);
	debug(step*2);
	debug(step*2+1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int cnt = 0 ;
		for(int i = 1;i <= n ;i ++ )
		{
			scanf("%d%d" , l+i,r+i);
			all[++cnt] = l[i];
			all[++cnt] = r[i];
		}
		sort(all+1,all+1+cnt);
		cnt = unique(all + 1, all + 1 + cnt ) - all -1;
		build(1,2* n + 2 ,1);
		for(int i = 1;i<=n ; i++)
		{
		//	cout << get_id(l[i],cnt) << " " << get_id(r[i],cnt) << " " << i << endl;
			update(get_id(l[i],cnt),get_id(r[i],cnt),i,1);
		}
		//debug(1);
		map<int,int>m;
		for(int i = 1;i<=2*n;i++)
		{
		//	cout << query(i,1) << endl;
			m[query(i,1)] = 1;
		}
		m.erase(0);
		printf("%d\n",m.size());
	}
}
