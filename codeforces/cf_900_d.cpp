#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
map<long long, long long> dp;
long long pow_mod(int x)
{
	if (!x)
		return 1;
	long long temp = pow_mod(x / 2);
	temp = temp * temp % MOD;
	if (x % 2)
		temp = temp * 2 % MOD;
	return temp;
}

long long dfs(int cur)
{
	if (cur == 1)
		return 1;
	if (dp.count(cur))
		return dp[cur];
	long long sum = pow_mod(cur - 1);
	sum = (sum - 1 + MOD) % MOD;
	for (int i = 2; i <= sqrt(cur); i++)
	{
		if (i * i == cur)
			sum = (sum - dfs(cur / i) + MOD) % MOD;
		else if (cur % i == 0)
		{
			sum = (sum - dfs(cur / i) + MOD) % MOD;
			sum = (sum - dfs(i) + MOD) % MOD;
		}
	}
	return dp[cur] = sum;
}

int main()
{
	long long x, y;
	while (cin >> x >> y)
	{
		dp.clear();
		if (y % x)
			cout << 0 << endl;
		else
			cout << ((dfs(y / x)) + MOD) % MOD << endl;
	}
}