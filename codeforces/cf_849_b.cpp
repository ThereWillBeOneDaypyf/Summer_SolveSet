#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

struct Point
{
	int x, y;
} p[1005];
int n;
double get_ratio(Point a, Point b)
{
	return (1.0 * (a.y - b.y)  / (a.x - b.x));
}
set<int>s[10000];
void init()
{
	for (int i = 0; i < 10000; i++)
		s[i].clear();
}
bool solve(int x)
{
	init();
	map<double, int>m;
	int cnt = 0;
	map<int, double>tran;
	double ans_tran = -1;
	int Max_size = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == x)
			continue;
		double k = get_ratio(p[x], p[i]);
		if (!m.count(k))
		{
			tran[cnt] = k;
			m[k] = cnt ++;
		}
		s[m[k]].insert(i);
		Max_size = max((int)s[m[k]].size(), Max_size);
	}
	set<int>tar;
	int flag = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (s[i].size() != Max_size || flag)
		{
			for (auto temp : s[i])
				tar.insert(temp);
		}
		else
		{
			ans_tran = tran[i];
			flag = 1;
		}
	}
	if (tar.size() == 1)
		return true;
	map<double, int> ans;
	double ans_k = 1e9 + 7;
	for (auto x : tar)
	{
		if (x == *(tar.begin()))
			continue;
		ans[get_ratio(p[x], p[*tar.begin()])] ++;
		ans_k = get_ratio(p[x], p[*tar.begin()]);
	}
	if (ans_k == 1e9 + 7)
		return false;
	if (ans.size() == 1 && ans_tran == ans_k)
		return true;
	else
		return false;
}
int main()
{
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			p[i].x = i;
			cin >> p[i].y;
		}
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (solve(i))
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}