#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...
vector<int>v;
int main()
{
	int n, k;
	while (cin >> k >> n)
	{
		if (n == 0 && k == 2)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			int res = 0;
			for (int i = 1; i <= k - 3; i++)
			{
				res ^= i;
				cout << i << " ";
			}
			if (k == 1)
				cout << n << endl;
			else if (k == 2)
				cout << 0 << " " << n << endl;
			else
			{
				int y = 1 << 17;
				if (res == n)
					cout << y << " " << y * 2 << " " << (y ^ (y * 2)) << endl;
				else cout << 0 << " " << y << " " << (y ^ n ^ res) << endl;
			}
		}
	}
}