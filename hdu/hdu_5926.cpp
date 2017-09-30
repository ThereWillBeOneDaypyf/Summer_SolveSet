#include<bits/stdc++.h>
using namespace std;


int Map[50][50];
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
int n, m;
bool judge(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int tx = x + xdir[i];
		int ty = y + ydir[i];
		if (tx < 1 || tx > n || ty < 1 || ty > m)
			continue;
		if (Map[x][y] == Map[tx][ty])
			return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &Map[i][j]);
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (judge(i, j))
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag)
		{
			set<int>s[2];
			for (int i = 1; i <= m; i++)
			{
				s[0].insert(Map[1][i]);
				s[1].insert(Map[n][i]);
			}
			if (s[0].size() < m || s[1].size() < m)
				flag = 1;
			s[0].clear(), s[1].clear();
			for (int i = 1; i <= n; i++)
			{
				s[0].insert(Map[i][1]);
				s[1].insert(Map[i][m]);
			}
			if (s[0].size() < n || s[1].size() < n)
				flag = 1;
		}
		printf("Case #%d: ", ++ka);
		if (!flag)
			printf("No\n");
		else printf("Yes\n");
	}
}