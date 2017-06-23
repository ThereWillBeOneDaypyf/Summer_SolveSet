#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5+5;
typedef long long ll;

ll dp[N][2];
int a[N];

ll dfs(int pos,int pre,int sta,bool limit)
{
	if(pos == -1)
		return 1;
	if(!limit && dp[pos][sta] != -1)
		return dp[pos][sta];
	int up = limit ? a[pos] : 1;
	ll ans = 0;
	for(int i =0;i<=up;i++)
	{
		if(pre == 1 && i == 1)
			continue;
		ans += dfs(pos-1,i,i==1,limit&&i==a[pos]);
	}
	if(!limit)
		dp[pos][sta] = ans;
	return ans;
}
ll solve(ll n)
{
	memset(dp,-1,sizeof(dp));
	memset(a,0,sizeof(a));
	int cnt = 0;
	while(n)
	{
		a[cnt++] = n % 2;
		n /= 2;
	}
	return dfs(cnt-1,-1,0,1);
}
int main()
{
	ll n;
	while(cin >> n)
	{
		cout << solve(n) << endl;
	}
}
