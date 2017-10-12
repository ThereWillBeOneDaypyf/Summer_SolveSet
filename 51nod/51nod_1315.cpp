#include<bits/stdc++.h>
using namespace std;

int vis[50];
bool judge(int x, int y)
{
	for (int i = 31; i >= 0; i--)
	{
		if ((x & y) != x)
			return false;
	}
	return true;
}
int main()
{
	int n, x;
	while (cin >> n >> x)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			int y;
			cin >> y;
			if (y <= x && judge(y, x))
			{
				for (int i = 31; i >= 0; i--)
					if ((1 << i) & y)
						vis[i] ++;
			}
		}
		int ans = 1e5;
		for (int i = 31; i >= 0; i--)
			if ((1 << i) & x)
				ans = min(ans, vis[i]);
		if (ans == 1e5)
			cout << 0 << endl;
		else
			cout << ans << endl;
	}
}