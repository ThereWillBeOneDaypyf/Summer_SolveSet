#include<bits/stdc++.h>
using namespace std;

int ans = 10000;
int n, a, b;
void dfs(int pos, int cnt, vector<int> ret, vector<int> v)
{
	if (pos >= 6)
	{
		ans = min(ans, (int)ret.size());
		return;
	}
	ret.push_back(n - v[pos]);
	dfs(pos + 1, cnt + 1, ret, v);
	ret.pop_back();
	for (auto &x : ret)
	{
		if (x >= v[pos])
		{
			x -= v[pos];
			dfs(pos + 1, cnt, ret, v);
			x += v[pos];
		}
	}
}

int main()
{
	while (cin >> n >> a >> b)
	{
		vector<int> v{a, a, a, a, b, b};
		ans = 10000;
		vector<int> ret;
		dfs(0, 0, ret, v);
		cout << ans << endl;
	}
}