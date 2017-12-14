#include<bits/stdc++.h>
using namespace std;

int Map[3005][12005];
const int N = 1e6 + 7;

vector<int> p;
vector<int> G[10000];
int vis[N];

void init()
{
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < N ; i++)
	{
		if (!vis[i])
		{
			p.push_back(i);
			for (int j = 2; j * i < N; j++)
			{
				vis[i * j] = 1;
			}
		}
	}
}
void init_info()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
}
int pre[10000];
int ok[100000];
int id[N];
int tot = 0;
bool dfs(int u)
{
	for (int v = 0; v < tot; v++)
	{
		if (Map[u][v] && !ok[v])
		{
			ok[v] = 1;
			if (pre[v] == -1 || dfs(pre[v]))
			{
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
int judge(int cur, int add, int last)
{
	if (add)
	{
		for (int i = last; i < cur; i++)
			for (auto v : G[i])
				Map[i][v] = 1;
		int ans = last;
		for (int i = last; i < cur; i++)
		{
			memset(ok, 0, sizeof(ok));
			if (dfs(i))
				ans ++;
		}
		if (ans == cur)
			return true;
		return false;
	}
	for (int i = 0; i < cur; i ++)
	{
		for (int j = 0; j < tot; j ++)
			Map[i][j] = 0;
		for (auto v : G[i])
			Map[i][v] = 1;
	}
	memset(pre, -1, sizeof(pre));
	int ans = 0;
	for (int i = 0; i < cur; i++)
	{
		memset(ok, 0, sizeof(ok));
		if (dfs(i))
		{
			ans ++;
		}
		else
			return ans;
	}
	return ans;
	if (ans == cur)
		return true;
	return false;
}
int main()
{
	int n;
	init();
	while (scanf("%d", &n) == 1)
	{
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		memset(id, -1, sizeof(id));
		tot = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < p.size(); j++)
			{
				if (v[i] < p[j])
					break;
				if (v[i] % p[j] == 0)
				{
					if (id[p[j]] == -1)
						id[p[j]] = tot ++;
					G[i].push_back(id[p[j]]);
				}
			}
		}
		int ans = judge(n, 0, 0);

		printf("%d\n", ans);
	}
}