#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

long long n;

int judge(int x, int y)
{
	int l = 1, r = 3500;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		long long tar = 1LL * n * x * y;
		long long cur = 4LL * x * y * mid - 1LL * n * y * mid - 1LL * n * x * mid;
		if (tar == cur)
			return mid;
		if (cur < tar)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

int main()
{
	while (cin >> n)
	{
		int flag = 0;
		for (int i = 1; i <= 3500; i++)
		{
			for (int j = 1; j <= 3500; j++)
			{
				int tar = judge(i, j);
				if (tar != -1)
				{
					flag = 1;
					cout << i << " " << j << " " << tar << endl;
					break;
				}
			}
			if (flag)
				break;
		}
	}
}