#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int ans = 0;
		for (auto op : s)
		{
			if (op == 'a' || op == 'e' || op == 'i' || op == 'o' || op == 'u')
				ans ++;
			else if (op >= '0' && op <= '9')
			{
				int x = op - '0';
				if (x % 2)
					ans ++;
			}
		}
		cout << ans << endl;
	}
}