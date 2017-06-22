#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...

const int N = 1e5 + 5;

int d[N];
int a[N];
int vis[N];
int n,m;
bool judge(int mid)
{
	int cur = mid - 1;
	memset(vis,0,sizeof(vis));
	for(int i = mid; i >= 1;i--)
	{
		cur = min(cur, i - 1);
		if(d[i] && !vis[d[i]] && a[d[i]] <= cur)
		{
			vis[d[i]] = 1;
			cur -= a[d[i]] + 1;
		}		
	}
	for(int i = 1;i<= m ; i++)
		if(!vis[i])
			return 0;
	return 1;
}

int main()
{
	while(cin >> n >> m)
	{
		for(int i = 1;i<=n;i++)
		{
			cin >> d[i];
		}
		for(int i  = 1;i<=m;i++)
			cin >> a[i];
		sort(a , a+m);
		int l = 0, r = n,mid;
		int ans = -1;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(judge(mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
