#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...


int n,m;
char Map[105][105];
int vis[105][105];
int xdir[8] = {0,1,0,-1,1,1,-1,-1};
int ydir[8] = {1,0,-1,0,-1,1,-1,1};
bool judge(int i,int j)
{
	if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || Map[i][j] == '*')
		return false;
	return true;
}
void dfs(int x,int y)
{
	if(!judge(x,y))
		return;
	vis[x][y] = 1;
	for(int i = 0;i<8;i++)
	{
		int tx = x + xdir[i];
		int ty = y + ydir[i];
		if(judge(tx,ty))
			dfs(tx,ty);
	}
}
int main()
{
	while(cin >> n >> m && (n && m))
	{
		for(int i =0;i<n;i++)
			for(int j=0;j<m;j++)
				cin >> Map[i][j];
		memset(vis,0,sizeof(vis));
		int ans = 0;
		for(int i = 0;i<n;i++)
			for(int j=0;j<m;j++)
				if(!vis[i][j]&&Map[i][j] == '@')
				{
					dfs(i,j);
					ans ++;
				}
		cout << ans << endl;
	}	
	return 0;	
}
