#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, pos, l, r;
	while (cin >> n >> pos >> l >> r)
	{
		if (r - l + 1 >= n)
		{
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		if (l != 1 && r != n)
		{
			if (pos < l)
				ans = r - pos;
			else if (pos > r)
				ans = pos - l;
			else
				ans = r - l + min(r - pos, pos - l);
			ans ++;
			ans ++;
		}
		else if (l == 1 && r != n)
		{
			if (pos > r)
				ans = pos - r;
			else
				ans = r - pos;
			ans ++;
		}
		else if (l != 1 && r == n)
		{
			if (pos < l)
				ans = l - pos;
			else
				ans = pos - l;
			ans ++;
		}
		cout << ans << endl;
	}
}