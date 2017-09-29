#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int pos1,pos2;
	int sta;
	int step;
};

int n,m;
int sx,sy;
int tar;
int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
char Map[10][10];
int vis[16][16][1 << 17];
int bfs()
{
	queue<Node>q;
	memset(vis,0,sizeof(vis));
	q.push({sx * m + sy,sx * m + sy,(1 << (sx * m + sy)),0});
	while(!q.empty())
	{
		Node temp;
		temp = q.front();
		q.pop();
		int step = temp.step;
		int x1 = temp.pos1 / m,y1 = temp.pos1 % m,x2 = temp.pos2 / m,y2 = temp.pos2 % m;
		int sta = temp.sta;
		if((sta & tar) == tar)
			return step;
		for(int i = 0;i<4;i++)
		{
			int tx1 = x1 + xdir[i];
			int ty1 = y1 + ydir[i];
			if(tx1 < 0 || tx1 >= n || ty1 < 0 || ty1 >= m || Map[tx1][ty1] == 'X')
				continue;
			for(int j = 0;j<4;j++)
			{
				int tx2 = x2 + xdir[j];
				int ty2 = y2 + ydir[j];
				if(tx2 < 0 || ty2 < 0 || tx2 >= n || ty2 >= m || Map[tx2][ty2] == 'X')
					continue;
				int cur_sta = (sta | (1 << (tx1 * m + ty1)) | ((1 << tx2 * m + ty2)));
				if(vis[tx1 * m + ty1][tx2 * m + ty2][cur_sta])
					continue;
				vis[x1 * m + y1][x2 * m + y2][sta] = 1;
				q.push((Node){tx1 * m + ty1,tx2 * m + ty2,(sta | (1 << (tx1 * m + ty1)) | (1 << (tx2 * m + ty2))),step+1});
			}

		}
	}
	return -1;
}
int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		string s;
		tar = 0;
		for(int i = 0;i<n;i++)
		{
			cin >> s;
			for(int j = 0;j != s.length();j++)
			{
				Map[i][j] = s[j];
				if(Map[i][j] == 'S')
					sx = i,sy = j;
				else if(Map[i][j] != 'X')
					tar += (1 << (i * m + j ));
			}
		}	
		cout << bfs() << endl;
	}
}
