#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int MOD = 1e9;

int dp[15][1<<15];
int Map[100][100];
int n,m;
bool judge(int pos,int status)
{
	for(int i = 0;i<m;i++)
	{
		if((status & (1<<i)) && !Map[pos][i])
			return false;
		if(status & (status << 1))
			return false;
	}
	return true;
}
int main()
{
	while(cin >> n >> m)
	{
		for(int i = 1;i<=n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cin >> Map[i][j];
			}
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 0;j < (1<<m);j++)
			{
				if(judge(i,j))
				{
					for(int k = 0;k<(1<<m);k++)
					{
						if((k & j) == 0)
							dp[i][j] =  (dp[i][j] + dp[i-1][k])%MOD;
					}
				}
			}	
		}
		int ans = 0;
		for(int i =0 ;i<(1<<m);i++)
			ans = (ans + dp[n][i]) % MOD;
		cout << ans << endl;
	}
}
