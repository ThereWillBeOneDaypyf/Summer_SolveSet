#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int cnt[2];
vector<int>G[N];
void dfs(int u, int fa, int flag)
{
	cnt[flag] ++;
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u, flag ^ 1);
	}
}
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		for (int i = 0 ; i < N; i++)
			G[i].clear();
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, 1, 0);
		long long ans = 1LL * cnt[0] * (cnt[0] - 1) + 1LL * cnt[1] * (cnt[1] - 1);
		ans /= 2;
		cout << ans << endl;
	}
}