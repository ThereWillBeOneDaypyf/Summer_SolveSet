#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int pre_sum[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(pre_sum, 0, sizeof(pre_sum));
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			pre_sum[i - 1] --;
			int Next = i - x - 1;
			Next = max(0, Next);
			pre_sum[Next] ++;
		}
		int ans = 0;
		for (int i = n; i >= 0; i--)
			pre_sum[i] += pre_sum[i + 1];
		for (int i = 1; i <= n; i++)
			if (pre_sum[i] >= 0)
				ans ++;
		cout << ans << endl;
	}
}