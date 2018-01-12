#include<bits/stdc++.h>
using namespace std;
const int N = 4e4;
int dp[N];
int main()
{
	int T;
	int m, n;
	cin >> T;
	while (T--)
	{
		cin >> m >> n;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		memset(dp, 0, sizeof(dp));
		for (auto i : v)
			for (int j = m; j >= i; j--)
				dp[j] = max(dp[j], dp[j - i] + i);
		cout << dp[m] << endl;
	}
}