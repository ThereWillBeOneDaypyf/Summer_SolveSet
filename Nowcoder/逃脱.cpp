#include<bits/stdc++.h>
using namespace std;

int n, m;
char Map[31][31];
int fire[31][31];
int vis[31][31];
int xdir[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int ydir[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int fx, fy;
int sx, sy;
int ex, ey;
struct Node
{
	int x, y;
	int step;
};
void GetFire()
{
	queue<Node> q;
	memset(fire, -1, sizeof(fire));
	q.push({fx, fy, 0});
	fire[fx][fy] = 0;
	while (!q.empty())
	{
		Node temp = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int tx = temp.x + xdir[i];
			int ty = temp.y + ydir[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m || fire[tx][ty] != -1)
				continue;
			fire[tx][ty] = temp.step + 1;
			q.push({tx, ty, temp.step + 1});
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		cout << fire[i][j] << " ";
	// 	cout << endl;
	// }
}

int bfs()
{
	queue<Node> q;
	q.push({sx, sy, 0});
	memset(vis, 0, sizeof(vis));
	while (!q.empty())
	{
		Node temp = q.front();
		q.pop();
		vis[temp.x][temp.y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int tx = temp.x + xdir[i], ty = temp.y + ydir[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m)
				continue;
			if (tx == ex && ty == ey && fire[tx][ty] >= temp.step + 1)
				return temp.step + 1;
			if (vis[tx][ty] || Map[tx][ty] == '#' || fire[tx][ty] <= temp.step + 1)
				continue;
			q.push({tx, ty, temp.step + 1});
		}
	}
	return -1;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				Map[i][j] = s[j];
				if (s[j] == '*')
					fx = i, fy = j;
				else if (s[j] == 'S')
					sx = i, sy = j;
				else if (s[j] == 'E')
					ex = i, ey = j;
			}
		}
		GetFire();
		int ans = bfs();
		if (ans == -1)
			cout << "T_T" << endl;
		else
			cout << ans << endl;
	}
}