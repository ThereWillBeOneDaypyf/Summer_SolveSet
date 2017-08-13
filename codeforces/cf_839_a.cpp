#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[1000];

int main()
{
	int n;
	int k;
	while (cin >> n >> k)
	{
		int cur = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			cur += a[i];
			int give = min(cur, 8);
			cur -= give;
			ans ++;
			k -= give;
			if (k <= 0)
				break;
		}
		if (k > 0)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
}