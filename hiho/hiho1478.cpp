#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

int Map[1000][1000];
int dis[1000][1000];
int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
int n,m;
bool ok(int x,int y)
{
	if(x < 0 || x >= n || y < 0 || y >= m)
		return false;
	return true;
}
void bfs()
{
	queue<pair<int,int> > q;
	memset(dis,-1,sizeof(dis));	
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(Map[i][j] == 0)
			{
				dis[i][j] = 0;
				q.push(make_pair(i,j));
			}
		}
	}
	while(!q.empty())
	{
		pair<int,int> temp = q.front();
		q.pop();
		for(int i = 0;i<4;i++)
		{
			int tx = temp.first + xdir[i];
			int ty = temp.second + ydir[i];
			if(ok(tx,ty) && dis[tx][ty] == -1)
			{
				dis[tx][ty] = dis[temp.first][temp.second] + 1;
				q.push(make_pair(tx,ty));
			}
		}
	}
}
int main()
{
	ios :: sync_with_stdio(false);	
	while(cin >> n >> m)
	{
		for(int i = 0;i<n;i++)
		{
			string s;
			cin >> s;
			for(int j = 0;j<m;j++)
				Map[i][j] = s[j] - '0';
		}
		bfs();
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cout << dis[i][j];
				if(j != m -1)
					cout << " ";
				else
					cout << endl;
			}
		}
	}
}

