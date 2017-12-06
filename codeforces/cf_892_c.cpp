#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>v;
		int flag = 0;
		int ok = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x == 1)
				ok ++;
			flag = __gcd(flag, x);
			v.push_back(x);
		}
		if (n == 1)
		{
			if (v[0] == 1)
				cout << 0 << endl;
			else
				cout << -1 << endl;
		}
		else if (flag != 1)
			cout << -1 << endl;
		else if (ok)
		{
			cout << n - ok << endl;
		}
		else
		{
			int ans = 1e9;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (__gcd(v[i], v[j]) == 1)
						ans = min(ans, abs(i - j));
				}
			}
			ans --;
			ans += (n);
			cout << ans << endl;
		}
	}
}