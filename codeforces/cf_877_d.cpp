#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int x, y;
	int step;
};

const int N = 1e3 + 7;
char Map[N][N];
int sx, sy, ex, ey;
int vis[N][N];
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
int n, m;
int k;
int bfs()
{
	queue<Node>q;
	q.push({sx, sy, 0});
	memset(vis, 0, sizeof(vis));
	vis[sx][sy] = 1;
	while (!q.empty())
	{
		Node temp = q.front();
		q.pop();
		if(temp.x == ex && temp.y == ey)
			return temp.step;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				int tx = temp.x + j * xdir[i];
				int ty = temp.y + j * ydir[i];
				if (tx < 0 || tx >= n || ty < 0 || ty >= m ||  Map[tx][ty] == '#')
					break;
				if (vis[tx][ty])
					continue;
				vis[tx][ty] = 1;
				if(tx == ex && ty == ey)
					return temp.step + 1;
				q.push({tx, ty, temp.step + 1});
			}

		}
	}
	return -1;
}

int main()
{
	while (~scanf("%d%d%d", &n, &m, &k))
	{
		char tar[N];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", tar);
			for (int j = 0; j < m; j++)
				Map[i][j] = tar[j];
		}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		sx --, sy --, ex--, ey--;
		cout << bfs() << endl;
	}
}
