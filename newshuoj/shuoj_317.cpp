#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int v[1000],w[1000];
int dp[100005];

int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		for(int i = 0;i<n;i++)
			cin >> w[i] >> v[i];
		memset(dp,0,sizeof(dp));
		for(int i = 0;i<n;i++)
			for(int j = m;j>=w[i];j--)
				dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
		cout << dp[m] << endl;
	}
	return 0;
}
