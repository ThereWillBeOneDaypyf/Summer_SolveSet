#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
//

const int N = 1e5;

int a[N];

int main()
{
	int n;
	int ka = 0;
	while (cin >> n)
	{
		if (n != 0 && ka++)
			cout << endl;
		else if(n == 0)
			break;
		int tot = 0;
		for (int i = 0 ; i < n; i++)
		{
			cin >> a[i];
			tot += a[i];
		}
		int per = tot / n;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += abs(per - a[i]);
		}
		ans /= 2;
		cout << ans << endl;
	}
}