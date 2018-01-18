#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> G[N];
int dfn[N], low[N];
int instack[N];
stack<int> st;
vector<int> VG[N];
int belong[N];
int Index = 0;
int cnt = 0;
int vis[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear(), VG[i].clear();
	memset(dfn, 0, sizeof(dfn));
	memset(vis, 0, sizeof(vis));
	memset(instack, 0, sizeof(instack));
	memset(belong, 0, sizeof(belong));
	while (!st.empty())
		st.pop();
	Index = cnt = 0;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++ Index;
	st.push(u);
	instack[u] = 1;
	for (auto v : G[u])
	{
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (instack[v])
			low[u] = min(low[u], dfn[v]);
	}
	int x;
	if (dfn[u] == low[u])
	{
		cnt ++;
		do
		{
			x = st.top();
			st.pop();
			instack[x] = 0;
			belong[x] = cnt;
		}
		while (x != u);
	}
}
void solve(int n)
{
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
}
bool dfs(int u)
{
	if (vis[u] == -1)
		return true;
	vis[u] = -1;
	for (auto v : G[u])
	{
		if (dfs(v))
		{
			vis[u] = 1;
			return true;
		}
	}
	vis[u] = 1;
	return false;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
		}
		solve(n);
		for (int i = 1; i <= n; i ++)
		{
			for (auto v : G[i])
			{
				if (belong[v] == belong[i])
				{
					VG[i].push_back(v);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++)
			if (!vis[i] && dfs(i))
				ans ++;
		cout << ans << endl;
	}
}