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

const int N = 1e5 + 5;

int dp[30][N];
int mul[N], w[N];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
			cin >> mul[i];
		for (int i = 1; i <= m; i++)
			cin >> w[i];
		CLR(dp, 0);
		dp[0][7500] = 1;
		for (int i = 1; i <= m; i++)
		{
			for (int k = 1; k <= n; k++)
			{
				int cur = mul[k] * w[i];
				for (int j = 15000; j >= cur; j--)
					dp[i][j] += dp[i - 1][j - cur];
			}
		}
		cout << dp[m][7500] << endl;
	}
}