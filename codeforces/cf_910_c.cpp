#include<bits/stdc++.h>
using namespace std;

long long c[10];
bool first[10];
int main()
{
	int n;
	while (cin >> n)
	{
		string s;
		memset(c, 0, sizeof(c));
		memset(first, 0, sizeof(first));
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			int base = 1;
			first[s[0] - 'a'] = 1;
			for (int j = s.length() - 1; j >= 0; j --)
			{
				c[s[j] - 'a'] += base;
				base *= 10;
			}
		}
		int vis[10];
		vector<pair<int, long long> > v;
		for (int i = 0; i < 10; i++)
			v.push_back(make_pair(i, c[i]));
		sort(v.begin(), v.end(), [](pair<int, long long> a, pair<int, long long> b)
		{
			return a.second > b.second;
		});
		long long ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < v.size(); i++)
		{
			if (!first[v[i].first])
			{
				vis[i] = 1;
				break;
			}
		}
		for (int i = 1; i < v.size(); i++)
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (!vis[j])
				{
					vis[j] = 1;
					ans += 1LL * i * v[j].second;
					//cout << v[j].first << " " << v[j].second << endl;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}