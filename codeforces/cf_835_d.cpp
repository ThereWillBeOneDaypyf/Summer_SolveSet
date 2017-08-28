#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int dp[5005][5005];
long long ans[5005];
int main()
{
	string s;
	while (cin >> s)
	{
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < s.length(); i++)
		{
			dp[i][i] = 1;
			ans[1]++;
			if (i < s.length() - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 2;
				ans[1]++, ans[2] ++;
			}
		}
		// for (int i = 0; i < s.length(); i++)
		// 	for (int j = 0; j < s.length(); j++)
		// 		cout << i << " " << j << " " << dp[i][j] << endl;
		for (int l = 1; l <= s.length(); l++)
		{
			for (int i = 0; i + l < s.length() - 1; i++)
			{
				if (s[i] == s[i + l + 1] && dp[i + 1][i + l])
					dp[i][i + l + 1] = dp[i][i + l / 2] + 1;
				for (int j = 1; j <= dp[i][i + l + 1]; j++)
					ans[j] ++;
			}
		}
		for (int i = 1; i <= s.length(); i++)
		{
			if (i != 1)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}