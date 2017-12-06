#include<bits/stdc++.h>
using namespace std;


bool judge(int tar)
{
	for (int i = 1; i <= 30; i++)
	{
		long long cur = (pow(2, i) - 1) * pow(2, i - 1);
		if (cur == tar)
			return true;
	}
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				if (judge(i))
				{
					ans = max(ans, i);
				}
			}
		}
		cout << ans << endl;
	}
}