#include<bits/stdc++.h>
using namespace std;

int Map[1000][1000];
int xdir[8] = {0,1,0,-1,1,1,-1,-1};
int ydir[8] = {1,0,-1,0,1,-1,1,-1};
int n,m;
void cal(int x,int y)
{
	for(int i = 0;i < 8;i++)
	{
		int tx = x + xdir[i];
		int ty = y + ydir[i];
		if(tx < 0 || tx >= n || ty < 0 || ty >= m)
			continue;
		if(Map[tx][ty] == -1)
			Map[x][y] ++;
	}
}

int main()
{
	while(cin >> n >> m && (n || m ))
	{
		memset(Map,-1,sizeof(Map));	
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m; j++)
			{
				char x;
				cin >> x;
				if(x == 'x')
					continue;
				else
					Map[i][j] = 0;
			}
		}
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j ++)
			{
				if(Map[i][j] == -1)
					continue;
				else cal(i,j);
			}
		}
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				if(Map[i][j] == -1)
					cout << 'x';
				else
					cout << Map[i][j];
			}
			cout << endl;
		}
	}
}
