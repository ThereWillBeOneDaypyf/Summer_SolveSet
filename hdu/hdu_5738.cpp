#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

vector<pair<long long, long long> >tar;
const int MOD = 1e9 + 7;
long long pow_mod(long long a, long long x)
{
	if (x == 0)
		return 1;
	long long temp = pow_mod(a, x / 2);
	temp = temp * temp % MOD;
	if (x  %  2)
		temp = temp * a  % MOD;
	return temp % MOD;
}
int main()
{
	int n;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		tar.clear();
		for (int i = 1; i <= n; i++)
		{
			long long x, y;
			scanf("%lld%lld", &x, &y);
			tar.push_back(make_pair(x, y));
		}
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			map<pair<long long, long long> , int> cnt;
			cnt.clear();
			for (int j = i + 1; j < n; j++)
			{
				long long y = tar[i].second - tar[j].second, x = tar[i].first - tar[j].first;
				long long G = __gcd(x, y);
				if (x == 0 && y == 0)
					cnt[make_pair(0, 0)] ++ ;
				else
					cnt[make_pair(y / G, x / G)]++;
			}
			for (map<pair<long long, long long>, int> :: iterator it = cnt.begin(); it != cnt.end(); it ++)
			{
				long long temp = it -> second;
				if (it -> first.first != 0 || it -> first.second != 0)
				{
					long long part1 = pow_mod(2, cnt[make_pair(0, 0)]);
					long long part2 = (pow_mod(2, temp) - 1 + MOD) % MOD;
					ans = ans + (part1 * part2) % MOD;
					ans %= MOD;
				}
				else
				{
					ans = ans + pow_mod(2, temp) % MOD;
					ans = (ans - 1 + MOD) % MOD;
				}
			}
		}
		printf("%lld\n", ans % MOD);
	}
}