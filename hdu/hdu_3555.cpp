#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e4;

long long dp[N][2];
int a[N];


long long dfs(int pos,int pre,int status,int limit)
{
	if(pos == -1)
		return 1;
	if(!limit && dp[pos][status] != -1)
		return dp[pos][status];
	int up = limit ? a[pos] : 9;
	long long ans = 0;
	for(int i = 0;i<=up;i++)
	{
		if(pre==6 && i == 2)
			continue;
		if(i == 4)
			continue;
		ans += dfs(pos-1,i,i == 6,limit && i == a[pos]);
	}
	if(!limit)
		dp[pos][status] = ans;
	return ans;
}
long long solve(int n)
{
	memset(dp,-1,sizeof(dp));
	memset(a,0,sizeof(a));
	int cnt = 0;
	while(n)
	{
		a[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt-1,-1,0,1);
}

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;
		cout << solve(m) - solve(n-1) << endl;
	}
}
