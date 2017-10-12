#include<bits/stdc++.h>
using namespace std;

vector<long long> v;
map<long long, int> vis;
void dfs(long long x)
{
	if (vis.count(x) || x > 1e18)
		return;
	v.push_back(x);
	vis[x] = 1;
	dfs(x * 2), dfs(x * 3), dfs(x * 5);
}

void f()
{
	v.clear();
	vis.clear();
	dfs(2), dfs(3), dfs(5);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

int main()
{
	f();
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		cout << *lower_bound(v.begin(), v.end(), n) << endl;
	}
}