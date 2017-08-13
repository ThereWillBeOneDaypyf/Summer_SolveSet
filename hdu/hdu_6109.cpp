#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

set<int> s[N];
int fa[N];
void init()
{
	for (int i = 1; i < N; i++)
		fa[i] = i, s[i].clear();
}
void push_up(int from, int to)
{
	for (auto x : s[from])
		s[to].insert(x);
}
int find(int x)
{
	if (fa[x] != x)
	{
		push_up(x, fa[x]);
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		fa[a] = fa[b];
}
void debug(int id)
{
	for (auto x : s[id])
		cout << x << " ";
	cout << endl;
}
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		int cur = 0;
		vector<int>ans;
		init();
		for (int i = 0; i < n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			x = find(x), y = find(y);
			if (!z)
			{
				if (find(x) == find(y))
				{
					ans.push_back(cur + 1);
					cur = 0;
					init();
				}
				else
				{
					s[find(y)].insert(find(x)) , s[find(x)].insert(find(y));
					cur ++;
				}
			}
			else
			{
				if (!s[find(x)].count(find(y)) && !s[find(y)].count(find(x)))
				{
					cur ++;
					merge(x, y);
				}
				else
				{
					ans.push_back(cur + 1);
					cur = 0;
					init();
				}
			}
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}
}