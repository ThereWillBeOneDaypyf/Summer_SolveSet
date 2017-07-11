#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Node
{
	int s,e;
	int id;
	bool operator < (const Node &rhs) const
	{
		return (e > rhs.e || (e == rhs.e && s < rhs.s));
	}
}a[N];
int BIT[N];
int n;
int lowbit(int x)
{
	return x & (-x);
}
void update(int x,int val)
{
	while(x < N)
	{
		BIT[x] += val;
		x += lowbit(x);
	}
}
int query(int x)
{
	int res = 0;
	while(x > 0)
	{
		res += BIT[x];
		x -= lowbit(x);
	}
	return res;
}
bool cmp(Node a,Node b)
{
	if(a.e == b.e)
		return a.s < b.s;
	return a.e > b.e;
}
int ans[N];
int main()
{
	int m;
	while(scanf("%d",&m)==1 && m)
	{
		memset(BIT,0,sizeof(BIT));
		memset(a,0,sizeof(a));
		memset(ans,0,sizeof(ans));
		int cnt = 0;
		for(int i = 0;i<m;i++)
		{
			scanf("%d%d",&a[i].s,&a[i].e);
			a[i].s ++,a[i].e ++;
			a[i].id = i;
		}
		sort(a,a+m);
		ans[a[0].id] = query(a[0].s);
		update(a[0].s,1);
		for(int i = 1;i<m;i++)
		{
			if(a[i-1].s == a[i].s && a[i-1].e == a[i].e)
				ans[a[i].id] = ans[a[i-1].id];
			else
				ans[a[i].id] = query(a[i].s);	
			update(a[i].s,1);
		}
		for(int i = 0;i<m;i++)
		{
			if(i)
				printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}

