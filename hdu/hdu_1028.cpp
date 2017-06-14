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
//
//int dp[200][200];
//
//int dfs(int n,int m) // he wei n chaishu
//{
//	if(dp[n][m])
//		return dp[n][m];
//	if(n==0||n==1||m==0||m==1)
//		return dp[n][m] = 1;
//	if(n < m)
//		return dp[n][m] = dfs(n,n);
//	else
//		return dp[n][m] = (dfs(n,m-1)+dfs(n-m,m));
//}
//
//void f()
//{
//	CLR(dp,0);
//	for(int i=1;i<=120;i++)
//	{
//		dfs(i,i);
//	}
//}
//int main()
//{
//	int n;
//	f();
//	while(cin >> n)
//	{
//		cout << dp[n][n] << endl;
//	}
//}
int c1[N];
int c2[N];

int main()
{
	int n;
	while(cin >> n)
	{
		CLR(c1,0);
		CLR(c2,0);
		for(int i=0;i<=n;i++)
			c1[i] = 1,c2[i] = 0;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				for(int k = 0;k<=n;k+=i)
				{
					c2[k+j] += c1[j];	
				}	
			}	
			for(int j = 0;j<=n;j++)
				c1[j] = c2[j] , c2[j] = 0;
		}	
		cout << c1[n] << endl;
	}
}
