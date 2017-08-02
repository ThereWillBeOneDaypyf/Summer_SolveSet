#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e3;
int Map[N][N];
int vis[N];
int pre[N];
int n;
char Graph[N][N];
int row_belong[N][N];
int col_belong[N][N];
bool dfs(int u)
{
	for (int i = 0; i <= n; i++)
	{
		if (!vis[i] && Map[u][i])
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
	for (int i = 0; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (dfs(i))
			ans ++;
	}
	return ans;
}
int main()
{
	while (cin >> n && n)
	{
		memset(Map, 0, sizeof(Map));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> Graph[i][j];
		int row = 0, col = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (Graph[i][j] == 'X')
				{
					while (j <= n && Graph[i][j] == 'X')
						j ++ ;
					j--;
					if (j != n)
						row ++;
				}
				else
					row_belong[i][j] = row;
			}
			row ++;
		}
		for (int j = 1; j <= n; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (Graph[i][j] == 'X')
				{
					while (i <= n && Graph[i][j] == 'X')
						i++;
					i --;
					if (i != n)
						col++;
				}
				else
					col_belong[i][j] = col;
			}
			col ++;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (Graph[i][j] == '.')
					Map[row_belong[i][j]][col_belong[i][j]] = 1;
			}
		}
		n = max(row, col);
		cout << hungry() << endl;
	}
}