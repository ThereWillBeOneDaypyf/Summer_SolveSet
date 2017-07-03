#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e3 + 5;

long long dp[N][N];
int Map[N][N];
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				cin >> Map[i][j];
				dp[i][j] = -INF;
			}
		}	
		for(int i = 1;i<=n;i++)
			dp[i][0] = -INF;
		for(int i = 1;i<=m;i++)
			dp[0][i] = -INF;
		dp[1][0] = 0,dp[0][1] = 0 ;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				int temp_j = j;
				int base = temp_j;
				while(base >= 2)
				{
					if(temp_j % base == 0)
						dp[i][j] = max(dp[i][j] , dp[i][temp_j/base] + Map[i][j]);
					base--;
				}
				dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i][j-1]) + Map[i][j]);
			}
		}
		cout << dp[n][m] << endl;
	}
}
