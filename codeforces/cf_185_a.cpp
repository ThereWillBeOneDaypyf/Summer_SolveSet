#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

const int MOD = 1e9 + 7;

ll pow_mod(int a, ll n)
{
	if (n == 0)
		return 1;
	ll res = pow_mod(a, n / 2);
	res = res * res % MOD;
	if (n % 2)
		res = res * a % MOD;
	return res;
}

int main()
{
	long long n;
	while (cin >> n)
	{
		if (n == 0)
		{
			cout << 1 << endl;
			continue;
		}
		ll ans = pow_mod(2, 2 * n - 1);
		ll ans1 = pow_mod(2, n - 1);
		cout << (ans + ans1) % MOD << endl;
	}
}