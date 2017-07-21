#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

const int N = 1e3;

ll a[N];
ll dp[N];
ll dfs(int pos, bool limit)
{
	if (pos == -1)
		return 1;
	if (!limit && dp[pos] != -1)
		return dp[pos];
	int up = limit ? a[pos] : 9;
	ll ans = 0;
	for (int i = 0; i <= up; i++)
	{
		if (i == 3 || i == 8)
			continue;
		ans += dfs(pos - 1, limit && i == a[pos]);
	}
	if (!limit)
		dp[pos] = ans;
	return ans;
}
ll solve(ll n)
{
	memset(dp, -1, sizeof(dp));
	memset(a, 0, sizeof(a));
	int cnt = 0;
	while (n)
	{
		a[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt - 1, 1);
}
int main()
{
	ll n;
	while (cin >> n && n)
	{
		cout << n << ": " << solve(n) - 1 << endl;
	}
}