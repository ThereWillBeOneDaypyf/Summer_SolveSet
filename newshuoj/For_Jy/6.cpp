#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 100;

int vis[N];
int a[N];
int main()
{
	int n;
	while (cin >> n)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			multiset<int>s;
			if (!vis[i])
			{
				ans ++;
				vis[i] = 1;
				s.insert(a[i]);
				for (int j = i + 1; j < n; j++)
				{
					if (!vis[j])
					{
						int flag = 1;
						for (auto temp : s)
							if (__gcd(temp, a[j]) != 1)
								flag = 0;
						if (flag)
						{
							vis[j] = 1;
							s.insert(a[j]);
						}
					}
				}
			}
		}
		cout  << ans << endl;
	}
}