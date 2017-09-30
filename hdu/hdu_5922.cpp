#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long n;
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		cin >> n;
		cout << "Case #" << ++ ka << ": ";
		cout << 1LL * (2 + n) * (n - 1) / 2 << endl;
	}
}