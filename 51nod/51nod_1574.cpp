#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N];
int b[N];
int pos[N];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			pos[a[i]] = i;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			ans += 1LL * abs(pos[x] - i);
		}
		cout << ans / 2 << endl;
	}
}