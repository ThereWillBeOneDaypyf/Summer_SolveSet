#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 5e5 + 7;

struct Node
{
	int l, r;
};
vector<Node>v[N];
map<int, int>m;
int solve(int id)
{
	int ans = 0;
	auto it = v[id].begin();
	ans ++;
	int r = it -> r;
	it ++;
	for (; it != v[id].end(); it ++)
	{
		if (it -> l >= r)
		{
			ans ++;
			r = it -> r;
		}
		else if (it -> r < r)
			r = it -> r;
	}
	return ans;
}
int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < N; i++)
			v[i].clear();
		m.clear();
		for (int i = 0; i < n; i++)
		{
			int d, l, r;
			cin >> d >> l >> r;
			if (!m.count(d))
				m[d] = cnt ++;
			l = l / 100 * 60 + l % 100;
			r = r / 100 * 60 + r % 100;
			v[m[d]].push_back({l, r});
		}
		for (int i = 0; i < n; i++)
			sort(v[i].begin(), v[i].end(), [](Node a, Node b) {return a.l < b.l || (a.l == b.l && a.r < b.r);});
		int ans = 0;
		for (int i = 0; i < cnt; i++)
			ans += solve(i);
		cout << "Scenario #" << ++ ka << ":" << endl;
		cout << ans << endl;
		cout << endl;
	}
}