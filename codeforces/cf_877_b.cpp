#include<bits/stdc++.h>
using namespace std;

int pre_a[10000];
int pre_b[10000];


int main()
{
	string s;
	while (cin >> s)
	{
		int n = s.length();
		memset(pre_a, 0, sizeof(pre_a));
		memset(pre_b, 0, sizeof(pre_b));
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'a')
				pre_a[i + 1] ++;
			if (s[i] == 'b')
				pre_b[i + 1] ++;
		}
		for (int i = 1; i <= n; i++)
		{
			pre_a[i] += pre_a[i - 1];
			pre_b[i] += pre_b[i - 1];
		}
		int ans = 1e9;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				int cur = pre_b[i - 1] + pre_a[j] - pre_a[i - 1] + pre_b[n] - pre_b[j];
				ans = min(ans, cur);
			}
		}
		cout << n - ans << endl;
	}
}