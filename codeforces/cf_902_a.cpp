#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[10000];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int cur = 0;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if (cur >= x)
				cur = max(cur, y);
		}
		if (cur >= m)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}