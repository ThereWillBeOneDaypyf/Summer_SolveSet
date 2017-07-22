#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3;

int Map[N][N];
int n, h, m, v;
int vis[N];
int flag = 0;
struct Node
{
	int id, c, d;
} a[N];
void init()
{
	memset(Map, -1, sizeof(Map));
	for (int i = 0; i <= n; i++)
		Map[i][i] = 0;
}
void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (Map[i][k] >= 0)
			{
				for (int j = 1; j <= n; j++)
				{
					if (Map[j][k] >= 0)
					{
						if (Map[i][j] == -1 || Map[i][k] + Map[k][j] < Map[i][j])
							Map[i][j] = Map[i][k] + Map[k][j];
					}
				}
			}
		}
	}
}
void dfs(int pos, int cur, int step)
{
	if (flag)
		return;
	if (step == h)
	{
		if (Map[pos][1] != -1 && cur - Map[pos][1] >= 0)
			flag = 1;
		return;
	}
	for (int i = 0; i < h; i++)
	{
		if (!vis[i] && Map[pos][a[i].id] != -1)
		{
			int temp = cur;
			temp -= (Map[pos][a[i].id] + a[i].d);
			if (temp < 0)
				continue;
			vis[i] = 1;
			dfs(a[i].id, temp + a[i].c, step + 1);
			vis[i] = 0;
			if (flag)
				return;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &v);
		init();
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			if (Map[u][v] == -1 || Map[u][v] > d)
				Map[u][v] = d, Map[v][u] = d;
		}
		floyd();
		scanf("%d", &h);
		for (int i = 0; i < h; i++)
		{
			int id, c, d;
			scanf("%d%d%d", &id, &c, &d);
			a[i] = {id, c, d};
		}
		flag = 0;
		memset(vis, 0, sizeof(vis));
		dfs(1, v, 0);
		if (flag)
			printf("%s\n", "YES");
		else
			printf("%s\n", "NO");
	}
}