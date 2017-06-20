#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1005;

int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
int dp[N][N];
int Map[N][N];
int n,m;

bool ok(int i,int j)
{
	if(i < 0 || i >= n || j < 0 || j >= m)
		return false;
	return true;
}

int dfs(int i,int j)
{
	if(dp[i][j])
		return dp[i][j];
	int Max = 0;
	for(int k =0 ;k<4;k++)
	{
		int tx = i + xdir[k];
		int ty = j + ydir[k];
		if(ok(tx,ty)&&Map[tx][ty] < Map[i][j] )
			Max = max(Max,dfs(tx,ty));
	}
	return dp[i][j] = Max + 1;
}

int main()
{
	while(cin >> n >> m)
	{
		memset(dp,0,sizeof(dp));
		for(int i =0 ;i<n;i++)
		{
			for(int j =0 ;j<m;j++)
			{
				cin >> Map[i][j];
			}
		}
		int ans = 0;
		for(int i =0 ;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				ans = max(ans,dfs(i,j));
			}
		}
		cout << ans << endl;
	}
}
