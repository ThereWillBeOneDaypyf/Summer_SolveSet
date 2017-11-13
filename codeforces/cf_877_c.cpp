#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 2)
		{
			cout << 3 << endl;
			cout << "2 1 2" << endl;
		}
		else
		{
			int ans = n / 2 * 3;
			if (n % 2)
				ans ++;
			cout << ans << endl;
			cout << 2;
			for (int i = 4; i <= n; i++)
				if (i % 2 == 0)
					cout << " " << i;
			for (int i = 1; i <= n; i++)
				if (i % 2)
					cout << " " << i;
			for (int i = 1; i <= n; i++)
				if (i % 2 == 0)
					cout << " " << i;
			cout << endl;
		}
	}
}