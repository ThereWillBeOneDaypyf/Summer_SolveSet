#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		vector<int> v;
		int ans = 0;
		int sum = 0;
		vector<int> status;
		for (int i = 0; i < n; i ++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0; i < n; i ++)
		{
			int x;
			cin >> x;
			status.push_back(x);
			if (x)
				sum += v[i];
		}
		for (int i = 0; i < k; i ++)
		{
			if (!status[i])
				sum += v[i];
		}
		ans = sum;
		for (int i = 0; i < n - k; i++)
		{
			if (!status[i])
				sum -= v[i];
			if (!status[i + k])
				sum += v[i + k];
			ans = max(ans, sum);
		}
		cout << ans << endl;
	}
}