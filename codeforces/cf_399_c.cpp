#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n, m;
	while (cin >> n >> m)
	{
		if (n == 0)
		{
			long long ans = - m * m;
			cout << ans << endl;
			for (int i = 0; i < m; i++)
				cout << 'x';
			cout << endl;
			continue;
		}
		long long cnt1 = m / n;
		long long ret1 = m - cnt1 * n;
		long long ans1 = 1LL * (cnt1 * cnt1 - 1) * n;
		ans1 += ret1 * ret1;
		long long ret2 = m - m / 2;
		long long ans2 = 1LL * n * n - 1LL * (m / 2 * m / 2) - 1LL * ret2 * ret2;
		if (ans1 > ans2)
		{
			long long cnt = m / n;
			long long ret = m - cnt * n;
			long long ans = 1LL * (cnt * cnt - 1) * n;
			ans += ret * ret;
			cout << -ans << endl;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < cnt; j++)
					cout << 'x';
				cout << 'o';
			}
			for (int i = 0; i < ret; i++)
				cout << 'x';
			cout << endl;
		}
		else
		{
			long long ret = m - m / 2;
			long long ans = 1LL * n * n - 1LL * (m / 2 * m / 2) - 1LL * ret * ret;
			cout << ans << endl;
			for (int i = 0; i < ret; i++)
				cout << 'x';
			for (int i = 0; i < n; i++)
				cout << 'o';
			for (int i = 0; i < m / 2; i++)
				cout << 'x';
			cout << endl;
		}
	}
}