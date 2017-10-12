#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long x, y;
		cin >> x >> y;
		long long z = (x + y) / 2;
		long long up = (y + z);
		long long down = (x + y + 2 * z);
		long long GCD = __gcd(up, down);
		cout << up / GCD << "/" << down / GCD << endl;
	}
}