#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int Map[1000][1000];
int dp[1000];

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				cin >> Map[i][j];
		memset(dp,0,sizeof(dp));
		for(int i = 1;i<=n;i++)
		{
			for(int j = m;j>0;j--)
			{
				for(int k = 1;k<=m;k++)
				{
					if(j >= k)
						dp[j] = max(dp[j-k] + Map[i][k],dp[j]);
				}
			}
		}
		cout << dp[m] << endl;
	}
}
