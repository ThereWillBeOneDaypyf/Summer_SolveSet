#include<bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 7;

long long pow_mod(long long x, long long a)
{
	if (a == 0)
		return 1;
	long long temp = pow_mod(x, a / 2);
	temp = temp * temp % MOD;
	if (a % 2)
		temp = temp * x % MOD;
	return temp;
}

int main()
{
	long long n, m;
	int tar;
	while (cin >> n >> m >> tar)
	{
		if (tar == -1 && (n % 2 != m % 2))
		{
			cout << 0 << endl;
			continue;
		}

		long long ans = pow_mod(2, n - 1) % MOD;
		long long res = pow_mod(ans, m - 1) % MOD;
		cout << res << endl;
	}
}