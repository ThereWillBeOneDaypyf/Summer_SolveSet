#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int pre_sum[N];

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		memset(pre_sum, 0, sizeof(pre_sum));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			pre_sum[x] ++;
		}
		int ans = 0;
		for (int i = 1; i <= m; i++)
		{
			pre_sum[i] += pre_sum[i - 1];
			if (pre_sum[i] >= k)
			{
				ans += (pre_sum[i] - (k - 1));
				pre_sum[i] = k - 1;
			}
		}
		for (int i = m + 1; i <= 1e6; i++)
		{
			pre_sum[i] += pre_sum[i - 1];
			int temp = pre_sum[i] - pre_sum[i - m];
			if (temp >= k)
			{
				pre_sum[i] = pre_sum[i - m] + k - 1;
				ans += (temp - (k - 1));
			}
		}
		cout << ans << endl;
	}
}