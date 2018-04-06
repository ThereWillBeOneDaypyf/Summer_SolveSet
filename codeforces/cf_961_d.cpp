#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[4];
vector<pair<int, int> > p;
bool vis[N];
int n;
bool judge_line(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
	double ratio1 = 1LL * (p1.second - p2.second) * (p1.first - p3.first);
	double ratio2 = 1LL * (p1.second - p3.second) * (p1.first - p2.first);
	return ratio2 == ratio1;
}
bool get_ans()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i ++)
		if (judge_line(p[0], p[1], p[i]))
			vis[i] = 1;
	vector<int> ret;
	for (int i = 0; i < n; i ++)
		if (!vis[i])
			ret.push_back(i);
	if (ret.size() <= 2)
		return true;
	else
	{
		for (int i = 2; i < ret.size(); i ++)
		{
			if (!judge_line(p[ret[0]], p[ret[1]], p[ret[i]]))
				return false;
		}
	}
	return true;
}
int main()
{
	default_random_engine engine(time(nullptr));
	while (cin >> n)
	{
		p.clear();
		for (int i = 0; i < n; i ++)
		{
			int x, y;
			cin >> x >> y;
			p.push_back(make_pair(x, y));
		}
		if (n < 4)
		{
			cout << "YES" << endl;
			continue;
		}
		vector<pair<int, int> > cur_p;
		int flag = 0;
		int cnt = 0;
		for (int i = 0; i < 4; i ++)
			a[i] = i;
		do
		{
			shuffle(p.begin(), p.end(),engine);
			if (get_ans())
			{
				flag = 1;
				break;
			}
		}
		while (cnt++ <= 100);
		if (flag)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}