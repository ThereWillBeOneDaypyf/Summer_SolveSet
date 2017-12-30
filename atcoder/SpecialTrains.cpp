#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n;
long long c[N], s[N], f[N];
long long solve(int pos)
{
	long long cur = s[pos] + c[pos];
	for (int i = pos + 1; i < n; i++)
	{
		long long fuck = ceil(1.0 * max(cur, s[i]) / f[i]);
		fuck *= f[i];
		cur = fuck + c[i];
	}
	return cur;
}
int main()
{
	while (cin >> n)
	{
		memset(c, 0, sizeof(c));
		memset(s, 0, sizeof(s));
		memset(f, 0, sizeof(f));
		int cur = 0;
		for (int i = 1; i < n; i ++)
			cin >> c[i] >> s[i] >> f[i];
		for (int i = 1; i <= n; i++)
			cout << solve(i) << endl;
	}
}