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

char s1[N];
char s2[N];
int dp[100][100];
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		CLR(dp, 0);
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> s1[i];
		for (int i = 1; i <= m; i++)
			cin >> s2[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (s1[i] == s2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << "Case " << ++ ka << endl;
		cout << dp[n][m] << endl;
	}
}