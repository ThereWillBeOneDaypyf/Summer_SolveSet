#include<bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int w, t;
		cin >> w >> t;
		int ans = 0;
		while (w > 120)
		{
			ans ++;
			w -= t;
		}
		cout << ans << endl;
	}
}