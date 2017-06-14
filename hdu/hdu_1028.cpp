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
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int,int> PII;
typedef long long ll;

const int N = 1e5+5;

int dp[200][200];

int dfs(int n,int m) // he wei n chaishu
{
	if(dp[n][m])
		return dp[n][m];
	if(n==0||n==1||m==0||m==1)
		return dp[n][m] = 1;
	if(n < m)
		return dp[n][m] = dfs(n,n);
	else
		return dp[n][m] = (dfs(n,m-1)+dfs(n-m,m));
}

void f()
{
	CLR(dp,0);
	for(int i=1;i<=120;i++)
	{
		dfs(i,i);
	}
}
int main()
{
	int n;
	f();
	while(cin >> n)
	{
		cout << dp[n][n] << endl;
	}
}
