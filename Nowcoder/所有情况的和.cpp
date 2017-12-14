#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long x[100000];

void init()
{
	x[0] = 1;
	for (int i = 1; i < 100000; i++)
	{
		x[i] = x[i - 1] * 2;
		x[i] %= MOD;
	}
}

int main()
{
	int n;
	init();
	while (cin >> n)
	{
		long long sum = 1;
		for (int i = 0; i < n; i++)
		{
			long long a, b;
			cin >> a >> b;
			sum = sum * (a + b);
			sum %= MOD;
		}
		cout << sum << endl;
	}
}