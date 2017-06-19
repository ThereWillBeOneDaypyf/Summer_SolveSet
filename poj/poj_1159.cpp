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
int dp[2][5005];
int main()
{
	string s;
	int n;
	while (cin >> n)
	{
		cin >> s;
		string rev_s(s.rbegin(), s.rend());
		CLR(dp, 0);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[i - 1] != rev_s[j - 1])
					dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
				else
					dp[i % 2][j] = dp[(i + 1) % 2][j - 1] + 1;
			}
		}
		cout << n - dp[n % 2][n] << endl;
	}
}
