#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int vis[1000];
int main()
{
	int n, x;
	while (cin >> n >> x)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			vis[t] = 1;
		}
		int ans = 0;
		for (int i = 0; i < x; i++)
			if (!vis[i])
				ans ++;
		if (vis[x])
			ans ++;
		cout << ans << endl;
	}
}