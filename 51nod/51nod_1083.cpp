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

const int N = 1e3 + 8;

int Map[N][N];
int dp[N][N];

int main()
{
	int n;
	while (cin >> n)
	{
		CLR(Map, 0);
		CLR(dp, 0);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> Map[i][j];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + Map[i][j];
		cout << dp[n][n] << endl;
	}
}