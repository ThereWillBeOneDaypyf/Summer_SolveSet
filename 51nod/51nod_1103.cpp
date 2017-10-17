#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

int pre[N];
long long dp[N];
int a[N];

long long pow_mod(int x)
{
	if(!x)
		return 1;
	long long temp = pow_mod(x / 2);
	temp = temp * temp % MOD;
	if(x % 2)
		temp = temp * 2 % MOD;
	return temp;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while(cin >> n)
	{
		memset(pre,0,sizeof(pre));
		memset(dp,0,sizeof(dp));
		for(int i = 1;i<=n;i++)
			cin >> a[i];	
		for(int i = 1;i<=n;i++)
		{
			dp[i] = dp[i - 1] * 2;
			if(!pre[a[i]])
				dp[i] ++;
			else
				dp[i] -= dp[pre[a[i]]-1];
			dp[i] = dp[i] + MOD;
			dp[i] %= MOD;
			pre[a[i]] = i;
		}
		cout << dp[n] << endl;
	}
}
