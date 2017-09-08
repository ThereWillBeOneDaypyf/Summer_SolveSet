#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = n / 2 ; i >= 1; i--)
		{
			if (__gcd(i, n - i) == 1)
			{
				cout << i << " " << n - i << endl;
				break;
			}
		}
	}
}