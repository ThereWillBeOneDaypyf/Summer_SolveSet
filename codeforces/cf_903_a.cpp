#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int x;
		cin >> x;
		int flag = 0;
		for (int i = 0 ; i <= 100; i ++)
		{
			int ret = x - i * 3;
			if (ret < 0)
				break;
			if (ret % 7 == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}