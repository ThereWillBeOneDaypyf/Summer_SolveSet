#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

//thansk to pyf ...
//thansk to qhl ...

const int N = 1e5;

int n, m;
vector<int>G[N];
int pre[N];
int vis[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
}
bool dfs(int u)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!vis[v])
		{
			vis[v] = 1;
			if (pre[v] == -1 || dfs(pre[v]))
			{
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
int hungry()
{
	memset(pre, -1, sizeof(pre));
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (dfs(i))
			ans ++;
	}
	return ans;
}
int main()
{
	while (cin >> n >> m)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
		}
		cout << hungry() << endl;
	}
}
