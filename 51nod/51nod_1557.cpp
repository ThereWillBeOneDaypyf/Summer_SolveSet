#include<bits/stdc++.h>
using namespace std;

int main()
{
	map<long long, long long> m;
	vector<long long> v;
	long long n, a, b;
	while (cin >> n >> a >> b)
	{
		m.clear();
		v.clear();
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
			m[x] ++;
		}
		int flag = 1;
		sort(v.begin(), v.end());
		if (a == b)
		{
			for (int i = 0; i < v.size(); i++)
			{
				if (m[v[i]] == 1)
				{
					if (!m.count(a - v[i]))
					{
						flag = 0;
						break;
					}
					if (m[a - v[i]] != 1)
					{
						flag = 0;
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < v.size(); i++)
			{
				bool ok = 0;
				if (m.count(a - v[i]))
					ok = 1;
				if (m.count(b - v[i]))
				{
					if (ok)
					{
						if (!m.count(-(a - v[i]) + b) && !m.count(-(b - v[i]) + a))
							ok = 0;
					}
					else ok = 1;
				}
				if (!ok)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}