#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[10000];
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		for (int i = 0; i < k; i++)
			cin >> a[i];
		int one = 0, two = 2 * n, four = n;
		for (int i = 0; i < k; i++)
		{
			int need_4 = a[i] / 4;
			if (four >= need_4)
			{
				a[i] -= need_4 * 4;
				four -= need_4;
			}
			else
			{
				a[i] -= four * 4;
				four = 0;
			}
		}
		for (int i = 0; i < k; i++)
		{
			int need_2 = a[i] / 2;
			if (two >= need_2)
			{
				a[i] -= need_2 * 2;
				two -= need_2;
			}
			else
			{
				a[i] -= two * 2;
				two = 0;
			}
		}
		two += four;
		one += four;
		four = 0;
		for (int i = 0; i < k; i++)
		{
			int need_2 = a[i] / 2;
			if (two >= need_2)
			{
				a[i] -= need_2 * 2;
				two -= need_2;
			}
		}
		one += two;
		for (int i = 0; i < k; i++)
		{
			if (one >= a[i])
			{
				one -= a[i];
				a[i] = 0;
			}
		}
		int flag = 1;
		for (int i = 0; i < k; i++)
			if (a[i])
				flag = 0;
		if (!flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}