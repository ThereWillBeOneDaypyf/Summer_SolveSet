#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long pow_mod(int x)
{
	if (x == 0)
		return 1;
	long long temp = pow_mod(x / 2);
	temp = temp * temp % MOD;
	if (x % 2)
		temp = temp * 2  % MOD;
	return temp;
}

int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		int n;
		cin >> n;
		cout << "Case #" << ++ ka << ": ";
		cout << (pow_mod(n) - 1 + MOD) % MOD << endl;
	}
}