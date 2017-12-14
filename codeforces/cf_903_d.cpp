#include<bits/stdc++.h>
using namespace std;

map<long long, int> cnt;
int main()
{
	freopen("1.in", "r", stdin);
	int n;
	while (cin >> n)
	{
		cnt.clear();
		long long ans = 0;
		long long sum = 0;
		for (int i = 1; i <= n; i ++)
		{
			int x;
			cin >> x;
			sum += x;
			ans += 1LL * i * x;
			ans -= sum;
			ans += cnt[x + 1];
			ans -= cnt[x - 1];
			cnt[x] ++;
		}
		cout << ans << endl;
	}
}