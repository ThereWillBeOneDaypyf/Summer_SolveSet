#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	while (cin >> n)
	{
		int cur = 3;
		int flag = 1;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x == cur)
				flag = 0;
			for (int j = 1; j <= 3; j++)
				if (j != x && j != cur)
				{
					cur = j;
					break;
				}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
