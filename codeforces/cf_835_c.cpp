#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int Map[500][500][20];
int ans[500][500][20];
int temp[20];
int main()
{
	int n, q, c;
	while (scanf("%d%d%d", &n, &q, &c) == 3)
	{
		memset(Map, 0, sizeof(Map));
		for (int i = 0; i < n; i++)
		{
			int x, y, s;
			scanf("%d%d%d", &x, &y, &s);
			temp[0] = s;
			for (int j = 1; j <= 12; j++)
			{
				temp[j] = temp[j - 1] + 1;
				if (temp[j] > c)
					temp[j] = 0;
			}
			for (int j = 0; j <= 12; j++)
				Map[x][y][j] += temp[j];
		}
		for (int j = 0; j <= 12; j++)
			for (int i = 1; i <= 100; i++)
			{
				ans[i][1][j] = ans[i - 1][1][j] + Map[i][1][j];
				ans[1][i][j] = ans[1][i - 1][j] + Map[1][i][j];
			}
		for (int k = 0; k <= 12; k++)
		{
			for (int i = 2; i <= 100; i++)
			{
				for (int j = 2; j <= 100; j++)
				{
					ans[i][j][k] = Map[i][j][k] + ans[i - 1][j][k] + ans[i][j - 1][k] - ans[i - 1][j - 1][k];
				}
			}
		}
		for (int i = 0; i < q; i++)
		{
			int t, bx, by, tx, ty;
			scanf("%d%d%d%d%d", &t, &bx, &by, &tx, &ty);
			t %= (c + 1);
			int res = ans[tx][ty][t] + ans[bx - 1][by - 1][t] - ans[bx - 1][ty][t] - ans[tx][by - 1][t];
			printf("%d\n", res);
		}
	}
}
