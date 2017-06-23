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
const int MOD = 1e7 + 7;
int dp[N][10];

void f()
{
	for (int i = 0; i < 8; i++)
		dp[1][i] = 1;
	for (int i = 2 ; i <= 1e6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0 ; k < 8; k++)
			{
				if ((j & k) == 0 && (j | k))
					dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}
}

int main()
{
	int n;
	f();
	while (cin >> n)
	{
		ll res = 0;
		for (int i = 0; i < 8; i++)
			res = (res + dp[n][i]) % MOD;
		cout << res << endl;
	}
}