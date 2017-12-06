#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> v[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		map<string, int> id;
		int tot = 0;
		for (int i = 0; i < n; i++)
		{
			string s;
			int t;
			cin >> s >> t;
			if (!id.count(s))
				id[s] = ++ tot;
			v[id[s]].push_back(t);
		}
		for (int i = 1; i <= tot ; i++)
			sort(v[i].begin(), v[i].end(), [](const int a, const int b) {return a > b;});
		long long sum = 0;
		for (int i = 1; i <= tot; i ++)
			for (int j = 0; j < min(2, (int)v[i].size()); j++)
				sum += v[i][j];
		cout << sum << endl;
	}
}