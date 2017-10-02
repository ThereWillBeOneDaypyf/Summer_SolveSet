#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

vector<pair<int, int> > v;

int main()
{
	ios :: sync_with_stdio(false);
	int n, k;
	while (cin >> n >> k)
	{
		v.clear();
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
			if ((a & k) == a)
				ans += b;
		}
		for (int i = 30; i >= 0; i--)
		{
			if ((k & (1 << i)) == 0)
				continue;
			int tar = ((k ^ (1 << i)) | ((1 << i) - 1));
			long long temp = 0;
			for (int i = 0; i < n; i++)
			{
				int a = v[i].first;
				int b = v[i].second;
				if ((a & tar) == a)
					temp += b;
			}
			ans = max(ans, temp);
		}
		cout << ans << endl;
	}
}