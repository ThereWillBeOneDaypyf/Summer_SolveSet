#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const long long  MAX = 1e18;

vector<long long>a, b;
set<long long>tar;
int main()
{
	long long x, y, l, r;
	while (cin >> x >> y >> l >> r)
	{
		a.clear(), b.clear();
		long long base = 1;
		a.push_back(1);
		b.push_back(1);
		while (base <= double(1.0 * MAX / x))
		{
			a.push_back(base * x);
			base *= x;
		}
		base = 1;
		while (base <= double(1.0 * MAX / y))
		{
			b.push_back(base * y);
			base *= y;
		}
		tar.clear();
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				if (a[i] + b[j] <= r && a[i] + b[j] >= l)
					tar.insert(a[i] + b[j]);
			}
		}
		if (tar.size() == 0 || tar.size() == (r - l + 1))
			cout << 0 << endl;
		else
		{
			set<long long> :: iterator it;
			it = tar.begin();
			long long ans = *it - l;
			long long temp = *it;
			it ++;
			for (; it != tar.end(); it++)
			{
				ans = max(ans, *it - temp - 1);
				temp = *it;
			}
			ans = max(ans, r - temp);
			cout << ans << endl;
		}
	}
}