#include<bits/stdc++.h>
using namespace std;

bool judge(int x, int y, int tx, int ty, int r)
{
	if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < r * r)
		return true;
	return false;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, q;
		cin >> n >> q;
		multiset<pair<int, int>> v;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			v.insert(make_pair(x, y));
		}
		int ans = 0;
		for (int i = 0; i < q; i++)
		{
			int x, y, rr;
			cin >> x >> y >> rr;
			auto l = lower_bound(v.begin(), v.end(), make_pair(x - rr, (int) - 1e9));
			auto r = lower_bound(v.begin(), v.end(), make_pair(x + rr, (int)1e9));
			vector<pair<int, int> > vis;
			for (auto it = l; it != r ; it ++)
			{
				if (judge((*it).first, (*it).second, x, y, rr))
				{
					ans ++;
					vis.push_back(*it);
				}
			}
			for (auto temp : vis)
				v.erase(v.find(temp));
		}
		cout << ans << endl;
		cout << endl;
	}
}