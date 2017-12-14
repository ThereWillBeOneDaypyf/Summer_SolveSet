#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int vis[N];

int main()
{
	int n;
	while (cin >> n)
	{
		memset(vis, 0, sizeof(vis));
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		int ans = 0;
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				ans ++;
				int cur = v[i];
				for (int j = i + 1; j < n; j ++)
				{
					if (vis[j])
						continue;
					if (cur < v[j])
					{
						cur = v[j];
						vis[j] = 1;
					}
				}
			}
		}
		cout << ans << endl;
	}
}