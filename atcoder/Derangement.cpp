#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 0;
		for (int i = 1; i < n; i++)
			if (a[i] == i)
			{
				swap(a[i], a[i + 1]);
				ans ++;
			}
		if (a[n] == n)
			ans ++;
		cout << ans << endl;
	}
}