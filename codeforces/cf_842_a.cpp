#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

int main()
{
	long long l , r, x, y, k;
	while (cin >> l >> r >> x >> y >> k)
	{
		int flag = 0;
		for (long long i = max(l / k, x) ; i <= y ; i++)
			if (i * k >= l && i * k <= r)
			{
				flag = 1;
				break;
			}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}