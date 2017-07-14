#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e2 + 7;

int Map[N][N];
int cx[N], cy[N], visx[N], visy[N], slack[N];
int pre[N];
int n;
int un, vn;
bool dfs(int u)
{
	visx[u] = 1;
	for (int v = 1; v <= vn; v++)
	{
		if (!visy[v] && cx[u] + cy[v] == Map[u][v])
		{
			visy[v] = 1;
			if (pre[v] == -1 || dfs(pre[v]))
			{
				pre[v] = u;
				return true;
			}
		}
		else
			slack[v] = min(slack[v], cx[u] + cy[v] - Map[u][v]);
	}
	return false;
}
int km()
{
	memset(cx, 0, sizeof(cx));
	for (int i = 1; i <= un; i++)
		for (int j = 1; j <= vn; j++)
			cx[i] = max(cx[i], Map[i][j]);
	memset(cy, 0, sizeof(cy));
	memset(pre, -1, sizeof(pre));
	for (int i = 1; i <= un; i++)
	{
		for (int j = 1; j <= vn; j++)
			slack[j] = INF;
		while (1)
		{
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (dfs(i))
				break;
			int d = INF;
			for (int j = 1; j <= vn; j++)
				if (!visy[j])
					d = min(d, slack[j]);
			for (int j = 1; j <= un; j++)
				if (visx[j])
					cx[j] -= d;
			for (int j = 1; j <= vn; j++)
				if (visy[j])
					cy[j] += d;
				else
					slack[j] -= d;
		}
	}
	int res = 0;
	for (int i = 1; i <= vn; i++)
		if (pre[i] != -1)
			res += Map[pre[i]][i];
	return res;
}
int val[N];
char x[N];
int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		un = vn = n;
		memset(Map, 0, sizeof(Map));
		for (int i = 1; i <= n; i++)
			scanf("%d", val + i);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", x + 1);
			for (int j = 1; j <= n; j++)
				Map[i][j] = x[j] - '0';
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (Map[i][j])
				{
					Map[i][j] = val[i] ^ val[j];
				}
			}
		}
		printf("%d\n", km());
	}
	return 0;
}
