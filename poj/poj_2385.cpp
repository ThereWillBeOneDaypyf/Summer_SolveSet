#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3 + 5;

int cnt[N][3];
int dp[N][100][3];

int main()
{
	int t,w;
	while(cin >> t >> w)
	{
		memset(dp,0,sizeof(dp));
		memset(cnt,0,sizeof(cnt));
		for(int i =1;i<=t;i++)
		{
			int x;
			cin >> x;
			cnt[i][x] = 1;
		}
		for(int i = 1;i <= t;i++)
		{
			for(int j = 0;j <= w;j++)
			{
				dp[i][j][1] = dp[i-1][j][1] + cnt[i][1];
				dp[i][j][2] = dp[i-1][j][2] + cnt[i][2];
				if(j)
				{
					dp[i][j][1] = max(dp[i-1][j-1][2] + cnt[i][1],dp[i][j][1]);
				  	dp[i][j][2] = max(dp[i-1][j-1][1] + cnt[i][2],dp[i][j][2]);	
				}
			}
		}
		int ans = 0;
		for(int j = 0;j<=w;j++)
			ans = max(ans , max(dp[t][j][1],dp[t][j][2]));
		cout << ans << endl;
	}
}
