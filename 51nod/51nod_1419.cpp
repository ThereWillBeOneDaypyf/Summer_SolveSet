#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	while(cin >> n)
	{
		if(n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		else if(n == 2)
		{
			cout << 2 << endl;
			continue;
		}
		long long ans = 0;
		long long res;
		for(int i = n - 2;i>=1;i--)
		{
			long long temp = n * (n - 1);
			temp = 1LL * temp / __gcd(temp,(long long)i) * i;
			if(temp > ans)
			{
				ans = temp;
				res = i;
			}
		}
		cout << res << endl;
		for(int i = n - 3;i>=1;i--)
		{
			long long temp = (n - 1) * (n - 2);
			temp = 1LL * temp / __gcd(temp,(long long)i) * i;
			if(temp > ans)
			{
				ans = temp;
				res = i;
			}
		}
		cout << res << endl;
	}
}

