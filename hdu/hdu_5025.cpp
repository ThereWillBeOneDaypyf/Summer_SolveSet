#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

struct Node
{
	int x, y, snack, key, step;
};
struct cmp
{
	bool operator()(Node a, Node b)
	{
		return a.step > b.step;
	}
};
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
int vis[102][102][33][10];
char Map[102][102];
int n, m;
int bfs(int sx, int sy)
{
	priority_queue<Node, vector<Node>, cmp>q;
	memset(vis, 0, sizeof(vis));
	q.push({sx, sy, 0, 0, 0});
	while (!q.empty())
	{
		Node temp = q.top();
		q.pop();
		int x = temp.x, y = temp.y , snack = temp.snack, key = temp.key, step = temp.step;
		if (vis[x][y][snack][key])
			continue;
		vis[x][y][snack][key] = 1;
		if (key == m && Map[x][y] == 'T')
			return step;
		for (int i = 0; i < 4; i++)
		{
			int tx = temp.x + xdir[i];
			int ty = temp.y + ydir[i];
			int tsnack = snack , tstep = step, tkey = key;
			if (tx < 0 || ty < 0 || tx >= n || ty >= n)
				continue;
			if (Map[tx][ty] == '#')
				continue;
			if (Map[tx][ty] >= 'A' && Map[tx][ty] <= 'G')
			{
				int id = Map[tx][ty] - 'A';
				if ((snack & (1 << id)) == 0)
				{
					tstep ++;
					tsnack = snack | (1 << id);
				}
			}
			else if (Map[tx][ty] == key + '0' + 1)
				tkey ++;
			tstep ++;
			q.push({tx, ty, tsnack, tkey, tstep});
		}
	}
	return -1;
}
int main()
{
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
			break;
		int cnt = 0;
		int sx, sy;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", Map[i]);
			for (int j = 0; j < n; j++)
			{
				if (Map[i][j] == 'K')
					sx = i, sy = j;
				else if (Map[i][j] == 'S')
					Map[i][j] = 'A' + cnt ++;
			}
		}
		int ans = bfs(sx, sy);
		if (ans == -1)
			printf("impossible\n");
		else
			printf("%d\n", ans);
	}
}