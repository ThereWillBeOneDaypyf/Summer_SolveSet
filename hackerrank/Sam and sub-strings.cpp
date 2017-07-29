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
const int MOD = 1e9 + 7;
long long dp[N];


int main()
{
	string s;
	while (cin >> s)
	{
		memset(dp, 0, sizeof(dp));
		dp[0] = 0;
		dp[1] = s[0] - '0';
		for (long long i = 1; i < s.length(); i++)
		{
			dp[i + 1] = (dp[i] * 10) % MOD + ((i + 1) * (s[i] - '0')) % MOD ;
			dp[i + 1] %= MOD;
		}
		long long ans = 0;
		for (int i = 1; i <= s.length(); i++)
			ans = (ans + dp[i]) % MOD;
		cout << ans % MOD << endl;
	}
}