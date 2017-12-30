#include<bits/stdc++.h>
using namespace std;

char Map[100][100];

int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
int pos[4];
int ans = 0;
int n, m;
string op;
bool dfs(int x, int y, int cur)
{
	if (x < 0 || x >= n || y < 0 || y >= m || Map[x][y] == '#')
		return false;
	if (Map[x][y] == 'E')
		return true;
	if (cur >= op.size())
		return false;
	return dfs(x + xdir[pos[op[cur] - '0']], y + ydir[pos[op[cur] - '0']], cur + 1);
}
int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0 ; i < 4; i++)
			pos[i] = i;
		int sx, sy;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				cin >> Map[i][j];
				if (Map[i][j] == 'S')
					sx = i, sy = j;
			}
		cin >> op;
		int ans = 0;
		do
		{
			if (dfs(sx, sy, 0))
				ans ++;
		}
		while (next_permutation(pos, pos + 4));
		cout << ans << endl;
	}
}