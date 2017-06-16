#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;
int dp[105][3]; // 0 buzuo 1 gym 2 contest
int day[105];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> day[i];
		}
		memset(dp, INF, sizeof(dp));
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[0][2] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
			if (day[i] == 1)
			{
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
			}
			else if (day[i] == 2)
			{
				dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
			}
			else if (day[i] == 3)
			{
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
				dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
			}
			//	cout << dp[i][0] <<" " << dp[i][1] <<" " << dp[i][2] << endl;
		}
		int Min = INF ;
		for (int i = 0; i < 3; i++)
			Min = min(Min, dp[n][i]);
		cout << Min << endl;
	}
	return 0;
}