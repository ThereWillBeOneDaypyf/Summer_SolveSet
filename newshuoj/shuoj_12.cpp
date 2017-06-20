#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
int n,m;
int Map[105][105];
int vis[105][105];
int flag = 0 ;

bool ok(int x,int y)
{
	if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || Map[x][y])
		return false;
	return true;
}

void dfs(int x,int y)
{
	if(!ok(x,y))
		return ;
	if(x == n-1 && y == m-1)
	{
		flag = 1;
		return;
	}
	vis[x][y] = 1;
	for(int i = 0;i<4;i++)
	{
		int tx = x + xdir[i];
		int ty = y + ydir[i];
		if(ok(tx,ty))
			dfs(tx,ty);
	}
}

int main()
{
	while(cin >> n >> m)
	{
		memset(vis,0,sizeof(vis));
		for(int i =0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> Map[i][j];
			}
		}
		flag = 0;
		dfs(0,0);
		if(flag)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}
