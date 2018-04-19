#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, a, b, c, t;
	while (cin >> n >> a >> b >> c >> t)
	{
		vector<int> v;
		long long sum = 0;
		for (int i = 0; i < n; i ++)
		{
			int x;
			cin >> x;
			v.push_back(x);
			sum += t - v[i];
		}
		if (b >= c)
		{
			cout << 1LL * n * a << endl;
		}
		else
		{
			cout << 1LL * n * a + sum * (c - b) << endl;
		}
	}
}