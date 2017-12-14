#include<bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int ret = n % m;
		if (ret == 0)
			cout << "YES" << endl;
		else if (m - ret <= k)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}