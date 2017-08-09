#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int f[300],t[300];
int dp[211][5010];
void solve(long long x, int i)
{
	t[i] = 0,f[i] = 0;
	while(x % 2 == 0)
	{x/= 2; t[i] ++;}
	while(x % 5 == 0)
	{x /= 5; f[i] ++;}
}
int main()
{
	int n,K;
	while(cin >> n >> K)
	{
		for(int i =1 ;i<=n;i++)
		{
			long long x;
			cin >> x;
			solve(x, i);
		}
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = K; j >= 1; --j) {
				for (int k = 5000; k >= f[i]; --k) {
					dp[j][k] = max(dp[j][k], dp[j - 1][k - f[i]] + t[i]);
				}
			}
		}
		int ans = 0;
		for(int i = 0;i<5000;i++)
			ans = max(ans,min(dp[K][i],i));	
		cout << ans << endl;
	}	
}
