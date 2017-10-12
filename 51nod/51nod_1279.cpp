#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

vector<pair<int, int> > well, plat;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		well.clear(), plat.clear();
		pair<int, int> st[50005];
		int top = 0;
		for (int i = 1; i <= n; i++)
		{
			int h;
			cin >> h;
			well.push_back(make_pair(h, i));
		}
		for (int i = 1; i <= m; i++)
		{
			int x;
			cin >> x;
			plat.push_back(make_pair(x, i));
		}
		for (auto temp : well)
		{
			if (!top)
			{
				st[++top] = temp;
				continue;
			}
			int h1 = temp.first;
			int h2 = st[top].first;
			if (h1 < h2)
				st[++top] = temp;
		}
		if (n == 1)
		{
			if (plat[0].first > st[top].first)
				cout << 1 << endl;
			else
				cout << 0 << endl;
			continue;
		}
		int ans = 0;
		st[++top] = make_pair(0, n);
		for (auto temp : plat)
		{
			if (top >= 2)
			{
				while (top != 1 && (st[top - 1].first < temp.first || st[top - 1].second == st[top].second))
					top --;
				if (top == 1)
					break;
				else
				{
					st[top].second --;
					ans ++;
				}
			}
		}
		cout << ans << endl;
	}
}