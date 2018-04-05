#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int vis[N];


int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i ++)
		{
			int x;
			cin >> x;
			vis[x] ++;
		}
		int ans = 1e9;
		for (int i = 1; i <= n; i ++)
		{
			ans = min(ans, vis[i]);
		}
		cout << ans << endl;
	}
}