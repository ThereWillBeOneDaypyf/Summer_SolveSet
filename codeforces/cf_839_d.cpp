#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thahks to qhl ...

typedef long long ll;

const int N = 1e6 + 8;
const int MOD = 1e9 + 7;
ll cnt[N];
ll f[N];
ll t[N];

int main()
{
	int n;
	t[0] = 1;
	for (int i = 1; i < N; i++)
		t[i] = t[i - 1] * 2 % MOD;
	while (cin >> n)
	{
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			cnt[x] ++;
		}
		long long ans = 0;
		for (int i = N - 1; i > 1; i--)
		{
			long long sz = 0;
			for (int j = i; j < N; j += i)
				sz += cnt[j];
			if (sz)
			{
				f[i] = 1LL * sz * t[sz - 1] % MOD;
				for (int j = i + i; j < N; j += i)
					f[i] = (f[i] - f[j] + MOD) % MOD;
				ans = ans + 1LL * i * f[i] % MOD;
				ans %= MOD;
			}
		}
		cout << ans << endl;
	}
}
