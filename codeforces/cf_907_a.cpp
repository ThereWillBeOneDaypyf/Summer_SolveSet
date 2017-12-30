#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		for (int i = 1; i <= 200; i ++)
		{
			for (int j = i + 1; j <= 200; j ++)
			{
				for (int k = j + 1; k <= 200; k ++)
				{
					if (a <= k && b <= j && c <= i && d <= i)
					{
						if (2 * d >= i && 2 * d < k && 2 * d < j)
						{
							if (2 * c >= i && 2 * a >= k && 2 * b >= j)
							{
								cout << k << " " << j << " " << i << endl;
								return 0;
							}
						}
					}
				}
			}
		}
		cout << -1 << endl;
	}
}