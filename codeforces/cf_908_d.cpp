#include<bits/stdc++.h>
using namespace std;

typedef  long long ll;
const int N = 1e6 + 5;
int inv[N];
const int MOD = 1e9 + 7;
int exgcd(int a, int b, int &x, int &y)
{
	int d = a;
	if (b != 0)
	{
		d = exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
	else x = 1, y = 0;
	return d;
}
int mod_inverse(int a, int m)
{
	int x, y;
	exgcd(a, m, x, y);
	return (m + x % m) % m;
}
long long dp[1005][1005];

int main()
{
	int k, a, b;
	while (cin >> k >> a >> b)
	{
		long long tara = mod_inverse(a, MOD);
		long long tarb = mod_inverse(b, MOD);
		long long tarab = mod_inverse(a + b, MOD);
		for (int i = k ; i >= 0; i --)
		{
			for (int j = 0; j <= k; j++)
			{
				if (i >= j)
					dp[i][j] = (a * tarb % MOD + i) % MOD;
				else
					dp[i][j] = (a * dp[i + 1][j] % MOD + b * (dp[i][j - i] + i) % MOD) % MOD * tarab % MOD;
			}
		}
		cout << dp[1][k] << endl;
	}
}