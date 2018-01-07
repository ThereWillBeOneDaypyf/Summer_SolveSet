#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n,p;
	while(cin >> n >> p)
	{
		if(p == 1)
		{
			cout << n << endl;
		}
		else
		{
			unsigned long long res = 0;
			while(res < n)
			{
				res <<= 1;
				res |= 1;
			}
			cout <<res << endl;
		}
	}
}
