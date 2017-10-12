#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int vis[N];
int n, k, a;
bool judge(int tar)
{
	int cnt = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i] || vis[i] > tar)
			cnt ++;
		else
			cnt = 0;
		if (cnt >= a)
			cnt = 0, sum ++, i ++;
	}
	return sum >= k;
}
int main()
{
	while (cin >> n >> k >> a)
	{
		memset(vis, 0, sizeof(vis));
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			int x;
			cin >> x;
			vis[x] = i;
		}
		int l = 1, r = m;
		int ans = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (judge(mid))
			{
				l = mid + 1;
			}
			else
			{
				ans = mid;
				r = mid - 1;
			}
		}
		cout << ans << endl;
	}
}