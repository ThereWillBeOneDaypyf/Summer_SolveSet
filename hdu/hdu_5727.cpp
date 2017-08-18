#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 12;
int pre[N], vis[N];
int Map[N][N];
int op[N][N];
int a[N];
int n, m;
bool dfs(int u)
{
	for (int i = 1; i <= n; i++)
	{
		if (Map[u][i] && !vis[i])
		{
			vis[i] = 1;
			if (pre[i] == -1 || dfs(pre[i]))
			{
				pre[i] = u;
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
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (int i = 1; i <= n; i++)
			a[i] = i;
		memset(op, 0, sizeof(op));
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			op[u][v] = 1;
		}
		int ans = n;
		do
		{
			a[0] = a[n];
			memset(Map, 0, sizeof(Map));
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (!op[i][a[j - 1]] && !op[i][a[j]])
						Map[i][j] = 1;
				}
			}
			ans = min(ans, n - hungry());
		}
		while (next_permutation(a + 2, a + 1 + n));
		printf("%d\n", ans);
	}
}