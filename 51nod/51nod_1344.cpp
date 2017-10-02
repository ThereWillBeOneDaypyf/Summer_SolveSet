#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			sum += x;
			if (sum < 0)
			{
				ans -= sum;
				sum = 0;
			}
		}
		cout << ans << endl;
	}
}