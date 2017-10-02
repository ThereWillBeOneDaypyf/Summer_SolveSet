#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int MOD = 1e9 + 7;

long long pow_mod(int x, int a)
{
	if (!a)
		return 1;
	long long temp = pow_mod(x, a / 2);
	temp = temp * temp % MOD;
	if (a % 2)
		temp = temp * x % MOD;
	return temp;
}

int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		vector<int>v;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += (v[i] * ((pow_mod(2, i) - 1 + MOD) % MOD)) % MOD;
			ans = (ans + MOD) % MOD;
			ans -= (v[i] * ((pow_mod(2, n - 1 - i) - 1 + MOD) % MOD)) % MOD;
			ans = (ans + MOD) % MOD;
		}
		cout << ans << endl;
	}
}