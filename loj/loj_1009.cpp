#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...

set<int>s[2];
int clr[100005];
vector<int>G[100005];
void dfs(int u, int flag)
{
	clr[u] = flag;
	s[flag].insert(u);
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (clr[v] == -1)
			dfs(v, flag ^ 1);
	}
}
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		memset(clr, -1, sizeof(clr));
		for (int i = 0; i < 100005; i++)
			G[i].clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v), G[v].push_back(u);
		}
		int ans = 0;
		for (int i = 1; i <= 20000; i++)
			if (G[i].size() && clr[i] == -1)
			{
				s[0].clear(), s[1].clear();
				dfs(i, 0);
				ans += max(s[0].size(), s[1].size());
			}
		cout << "Case " << ++ ka << ": ";
		cout << ans << endl;
	}
}