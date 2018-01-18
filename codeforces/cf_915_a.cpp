#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int ans = 1e9;
		for (int i = 0 ; i < n; i++)
		{
			int x;
			cin >> x;
			if (k % x == 0)
				ans = min(ans, k / x);
		}
		cout << ans << endl;
	}
}