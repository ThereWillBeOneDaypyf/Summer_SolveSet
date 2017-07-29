#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;

int dp[N];

int main()
{
	string s;
	while (cin >> s)
	{
		memset(dp, 0, sizeof(dp));
		stack<int>st;
		int ans = 0;
		int cnt = 1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				st.push(i + 1);
			else
			{
				if (st.empty())
					continue;
				int t = st.top();
				st.pop();
				dp[i + 1] = dp[t - 1] + i - t + 2;
				if (dp[i + 1] > ans)
					ans = dp[i + 1], cnt = 1;
				else if (dp[i + 1] == ans)
					cnt ++;
			}
		}
		cout << ans << " " << cnt << endl;
	}
}