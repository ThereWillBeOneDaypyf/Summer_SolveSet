#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		int i;
		int cur = a;
		for (i = 1 ; i <= 1e6; i++)
		{
			a *= 10;
			int cur = a / b;
			a %= b;
			if (cur == c)
				break;
		}
		if (i > 1e6)
			cout << -1 << endl;
		else
			cout << i << endl;
	}
}