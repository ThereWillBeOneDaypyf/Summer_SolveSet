#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6+9;

int a[N];
int n;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x)
{
	while(x <= n)
	{
		a[x] ++;
		x += lowbit(x);
	}
}
int query(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans += a[x];
		x -= lowbit(x);
	}
	return ans;
}
int tar[N];
int b[N];
int get_id(int x,int cnt)
{
	return lower_bound(tar,tar+cnt,x) - tar;
}
int main()
{
	while(scanf("%d",&n)==1 && n)
	{
		memset(a,0,sizeof(a));
		memset(tar,0,sizeof(tar));
		for(int i = 0;i<n;i++)
		{
			scanf("%d",b+i);
			tar[i] = b[i];
		}
		sort(tar,tar+n);
		int cnt = unique(tar,tar+n) - tar;
		long long ans = 0;
		for(int i = 0;i<n;i++)
		{
			int res = get_id(b[i],cnt);
			res ++;
			ans += query(cnt) - query(res-1);
			update(res);
		}
		printf("%lld\n",ans);
	}
}
