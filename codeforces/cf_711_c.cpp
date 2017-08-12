#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const long long INF = 1e18;
int Map[105][105];
int c[105];
long long dp[105][105][105];
int main()
{
	ios :: sync_with_stdio(false);
	int n,m,K;
	while(cin >> n >> m >> K)
	{
		for(int i = 1;i<=n;i++)
			cin >> c[i];
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				cin >> Map[i][j];
		for(int i = 0;i<=n;i++)
			for(int j = 0;j<=K;j++)
				for(int k = 0;k<=m;k++)
					dp[i][k][j] = INF;
		if(c[1])
			dp[1][c[1]][1] = 0;
		else
			for(int i = 1;i<=m;i++)
				dp[1][i][1] = Map[1][i];
		for(int i = 2;i<=n;i++)
		{
			if(c[i])
			{
				for(int j = 1;j<=m;j++)
				{
					for(int k = 1;k<=K;k++)
					{
						if(j == c[i])
							dp[i][j][k] = min(dp[i][j][k],dp[i-1][j][k]);
						else
							dp[i][c[i]][k] = min(dp[i][c[i]][k],dp[i-1][j][k-1]);
					}
				}
			}
			else
			{
				for(int k = 1;k<=K;k++)
				{
					for(int cur_c = 1;cur_c <= m;cur_c ++)
					{
						for(int pre_c = 1;pre_c <= m;pre_c ++)
						{
							if(cur_c == pre_c)
								dp[i][cur_c][k] = min(dp[i][cur_c][k],dp[i-1][pre_c][k] + Map[i][cur_c]);
							else
								dp[i][cur_c][k] = min(dp[i][cur_c][k],dp[i-1][pre_c][k-1] + Map[i][cur_c]);
						}
					}
				}
			}
		}
		long long ans = INF;
		for(int j = 1;j<=m;j++)
		{
			ans = min(ans,dp[n][j][K]);
		}
		if(ans >= INF)
			ans = -1;
		cout << ans << endl;
	}
}
