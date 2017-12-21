#include<bits/stdc++.h>
using namespace std;

long long sqare[100000];

void init()
{
	for (int i = 0; i < 1e5; i ++)
		sqare[i] = 1LL * i * i;
}

long long solve(long long x)
{
	int pos = lower_bound(sqare, sqare + 100000, x) - sqare;
	if (sqare[pos] == x)
		return 0;
	if (pos == 0)
		return x;
	return min(x - sqare[pos - 1], sqare[pos] - x);
}

int main()
{
	int n;
	init();
	while (cin >> n)
	{
		vector<long long> v;
		vector<long long> dif;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			long long  x;
			cin >> x;
			long long temp = solve(x);
			dif.push_back(temp);
			if (!x)
				v.push_back(2);
			else if (!temp)
				v.push_back(1);
			else v.push_back(0);
			if (!temp)
				cnt ++;
		}
		long long ans = 0;
		if (cnt >= n / 2)
		{
			sort(v.begin(), v.end());
			for (int i = 0; i < n / 2; i ++)
				ans += v[i];
		}
		else
		{
			sort(dif.begin(), dif.end());
			for (int i = 0; i < n / 2; i ++)
				ans += dif[i];
		}
		cout << ans << endl;
	}
}