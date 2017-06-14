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
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int,int> PII;
typedef long long ll;

const int N = 1e5+5;

int Map[1005][1006];
int dp[1005][1005];

int main()
{
	int n;
	while(cin >> n )
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=i;j++)
				cin >> Map[i][j];
		}
		CLR(dp,0);
		for(int i=0;i<n;i++)
			dp[n-1][i] = Map[n-1][i];
		for(int i=n-2;i>=0;i--)
		{
			for(int j=0;j<=i;j++)
			{
				dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + Map[i][j];
			}
		}
		cout << dp[0][0] << endl;
	}
}
