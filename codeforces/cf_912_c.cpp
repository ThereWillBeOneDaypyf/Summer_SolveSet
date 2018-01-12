#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int vis[N];
long long MaxH[N], stH[N], re[N];
long long time[N], id[N], changeH[N];
vector<pair<int, int> > G[N];
vector<pair<long long, long long> > res;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < N; i++)
			G[i].clear();
		long long base, upratio, damage;
		cin >> base >> upratio >> damage;
		int fuck = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> MaxH[i] >> stH[i] >> re[i];
			if (MaxH[i] <= damage)
			{
				vis[i] = 1;
				fuck ++;
			}
		}
		if (fuck)
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> time[i] >> id[i] >> changeH[i];
			G[id[i]].push_back(make_pair(time[i], changeH[i]));
		}
		res.clear();
		for (int i = 1; i <= n; i++)
		{
			if (vis[i])
				continue;
			sort(G[i].begin(), G[i].end());
			long long shouldl = 0;
			long long shouldr = (damage - stH[i]) / re[i];
			for (auto temp : G[i])
			{
				long long st = temp.first;
				long long curH = temp.second;
				if (st > shouldr)
					res.push_back(shouldl, shouldr);
				else
					res.push_back(shouldl, st - 1);
				shouldl = st;
				shouldr = (damage - temp.second) / re[i];
			}
			res.push_back(shouldl, shouldr);
		}
		sort(res.begin(), res.end(), [](pair<long long, long long>a, pair<long long, long long> b)
		{
			return a.second < b.second;
		});
		long long ans = 0;
		for (int i = 0; i < n; i ++)
		{
			int pos = search(i + 1, n - 1);

		}
	}
}