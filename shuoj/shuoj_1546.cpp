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

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

int a[4] = {10, 20, 50, 100};
int dp[N];
int main()
{
	int n;
	while (cin >> n)
	{
		CLR(dp, 0);
		dp[0] = 1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = a[i]; j <= n; j++)
			{
				if (dp[j - a[i]] != -1)
				{
					dp[j] += dp[j - a[i]];
				}
			}
		}
		if (dp[n] == -1)
			cout << 0 << endl;
		else
			cout << dp[n] << endl;
	}
}