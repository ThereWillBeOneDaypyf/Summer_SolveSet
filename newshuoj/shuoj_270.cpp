#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

int t[N];
int v[N];
int dp[N];
int main()
{
	int T,n;
	while(cin >> T >> n)
	{
		memset(dp,0,sizeof(dp));
		for(int i =0;i<n;i++)
		{
			cin >> t[i] >> v[i];
		}
		for(int i =0;i<n;i++)
		{
			for(int j = T;j>=t[i];j--)
			{
				dp[j] = max(dp[j],dp[j-t[i]] + v[i]);
			}
		}
		cout << dp[T] << endl;
	}
}
