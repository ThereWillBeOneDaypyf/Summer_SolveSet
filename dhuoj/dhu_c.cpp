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
const ll MOD = 1e9 + 7;

ll dp[N];

ll pow_mod(int a, int n)
{
	if (n == 0)
		return 1;
	ll x = pow_mod(a, n / 2);
	ll ans = x * x % MOD;
	if (n % 2 == 1)
		ans = ans * a % MOD;
	return ans;
}

int main()
{
	ll n , l;
	while (scanf("%lld%lld", &n, &l) == 2)
	{
		ll sum = 0;
		CLR(dp, 0);
		for (int i = 1; i <= l; i++)
		{
			dp[i] = pow_mod(2, i - 1);
			sum = (sum + dp[i] % MOD) % MOD;
		}
		for (int i = l + 1; i <= n; i++)
		{
			dp[i] = sum;
			sum  = (sum - dp[i - l] + dp[i] + MOD) % MOD ;
		}
		printf("%lld\n", dp[n]);
	}
}