#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int dp[10];
int a[10];

int main()
{
	int T;
	cin >> T;
	int n ;
	while(T--)
	{
		n = 5;
		for(int i =0 ;i<n;i++)
			cin >> a[i];
		for(int i = 0;i<n;i++)
		{
			dp[i] = 1;
			for(int j=0;j<i;j++)
			{
				if(a[i] > a[j] )
					dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		int ans = 0;
		for(int i = 0;i<n;i++)
			ans = max(ans,dp[i]);
		for(int i = 0;i<n;i++)
		{
			dp[i] = 1;
			for(int j = 0;j<i;j++)
			{
				if(a[i] < a[j] )
					dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		for(int i = 0;i<n;i++)
			ans = max(ans,dp[i]);
		cout << ans << endl;
	}
}
