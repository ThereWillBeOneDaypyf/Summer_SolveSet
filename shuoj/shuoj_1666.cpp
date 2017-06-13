#include <bits/stdc++.h>
using namespace std;
int a[5000];
int n;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	while (cin >> T)
		while (T--)
		{
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}
			sort(a, a + n);
			int ans = n / 2;
			long long aa = 0;
			for (int i = 0; i < n; i++)
			{
				aa += abs(a[i] - a[ans]);
			}
			cout << aa << endl;
		}
}