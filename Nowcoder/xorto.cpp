#include<bits/stdc++.h>
using namespace std;

const int N = 1 << 17;

vector<int>v;
vector<pair<int, int> >s[N];
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		v.clear();
		for (int i = 0; i < N; i++)
			s[i].clear();
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		for (int i = 0; i != n; i++)
		{
			int temp = 0;
			for (int j = i; j != n; j++)
			{
				temp ^= v[j];
				s[temp].push_back(make_pair(i, j));
			}
		}
		long long ans = 0;
		for (int i = 0; i < N; i++)
		{
			if (s[i].size() == 0)
				continue;
			sort(s[i].begin(), s[i].end());
			for (int j = 0; j < s[i].size(); j++)
			{
				auto r = 	upper_bound(s[i].begin(), s[i].end(), make_pair(s[i][j].second, (int)2e9 + 7));
				if (r == s[i].end())
					continue;
				ans += (long long)((int)s[i].size() - (r - s[i].begin()));
			}
		}
		printf("%lld\n", ans);
	}
}