#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...



const int N = 1e3 + 5;
const __int64 INF = 1e18;
__int64 c[5];
__int64 l[5];
__int64 point[N];
__int64 Map[N][N];
int dis[N][N];

__int64 get_cost(long long tar)
{
	for (int i = 1; i <= 4; i++)
	{
		if (tar > l[i - 1] && tar <= l[i])
			return c[i];
	}
	return INF;
}
int main()
{
	int T;
	int ka = 0;
	scanf("%d", &T);
	while (T--)
	{
		memset(l, 0, sizeof(l));
		memset(c, 0, sizeof(c));
		memset(Map, 0, sizeof(Map));
		for (int i = 1; i <= 4; i++)
			scanf("%I64d", l + i);
		for (int i = 1; i <= 4; i++)
			scanf("%I64d", c + i);
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n ; i++)
			scanf("%I64d", point + i);
		for (int i = 1; i <= n ; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				Map[i][j] = get_cost(abs(point[i] - point[j]));
			}
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
				}
			}
		}
		printf("Case %d:\n", ++ka);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if (Map[u][v] == INF)
				printf("Station %d and station %d are not attainable.\n", u, v);
			else
				printf("The minimum cost between station %d and station %d is %I64d.\n", u, v, Map[u][v]);
		}
	}
}