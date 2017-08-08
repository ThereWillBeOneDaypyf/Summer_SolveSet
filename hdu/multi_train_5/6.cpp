#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long n, m;
		scanf("%lld%lld", &n, &m);
		long long ans = 0;
		if (m < n - 1)
		{
			long long part1 = m + 1; // tree
			long long part2 = n - part1;
			ans = (long long)(part1 - 1) * (long long)(part1 - 2) + (long long)part1 - 1LL;
			ans += (long long) part2 * part1 * n + part2 * (part2 - 1) / 2 * n;
		}
		else if (n * (n - 1) / 2 <= m)
		{
			ans = n * (n - 1) / 2;
		}
		else
		{
			ans = (long long)(n - 1) * (n - 2) + n - 1LL;
			ans -= (long long)(m - (n - 1));
		}
		printf("%lld\n", ans * 2);
	}
}