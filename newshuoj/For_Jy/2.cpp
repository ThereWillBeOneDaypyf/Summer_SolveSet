#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 8;
const int MOD = 32767;
long long a[N];

int main()
{
	memset(a, 0, sizeof(a));
	a[1] = 1, a[2] = 2;
	for (int i = 3; i < N; i++)
	{
		a[i] = (2 * a[i - 1]) % MOD + a[i - 2];
		a[i] %= MOD;
	}
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << a[n] << endl;
	}
}
