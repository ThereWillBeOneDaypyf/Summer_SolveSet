#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e4 + 7;

int a[N * 2];

int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		for (int i = 0; i < n; i++)
			a[i + n] = a[i];
		for (int i = 3; i <= n ; i++)
		{
			if (n % i == 0)
			{
				for (int k = 0; k < n / i; k++)
				{
					int cnt = 0;
					int temp = 0;
					for (int j = k;; j += n / i)
					{
						cnt ++;
						temp += a[j];
						if (cnt == i)
							break;
					}
					sum = max(sum, temp);
				}
			}
		}
		cout << sum << endl;
	}
}