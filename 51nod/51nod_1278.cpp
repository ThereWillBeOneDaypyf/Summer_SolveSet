#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thansk to qhl ...

vector<pair<int, int> > v;

int main()
{
	int n;
	while (cin >> n)
	{
		v.clear();
		for (int i = 0; i < n; i++)
		{
			int x, r;
			cin >> x >> r;
			v.push_back(make_pair(x - r, x  + r));
		}
		sort(v.begin(), v.end());
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			auto r = upper_bound(v.begin(), v.end(), make_pair(v[i].second, (int)2e9 + 7));
			if (r == v.end())
				continue;
			ans += (long long)(n - (r - v.begin()));
		}
		cout << ans << endl;
	}
}