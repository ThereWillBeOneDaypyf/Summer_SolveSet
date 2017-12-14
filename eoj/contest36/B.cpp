#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, m;
	while (cin  >> n >> m)
	{
		if (n > m)
			swap(n, m);
		if (n == 3 && m == 3)
			cout << 28 << endl;
		else if (n == 1 || m == 1)
			cout << 0 << endl;
		else if (n == 2)
		{
			int cnt = m / 2;
			int ret = m % 2;
			long long ans = 0;
			if (!ret)
				ans = 4LL * cnt * (cnt - 1) / 2;
			else
			{
				ans = 2LL * cnt * (cnt - 1) / 2;
				ans += 2LL * cnt * (cnt + 1) / 2;
			}
			cout << ans << endl;
		}
		else
		{
			long long all = n * m;
			cout << all * (all - 1) / 2 << endl;
		}
	}
}