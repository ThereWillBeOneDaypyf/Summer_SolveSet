#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int prime[N];

void f()
{
	memset(prime, 0, sizeof(prime));
	prime[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (prime[i] == 1)
			continue;
		for (int j = 2; i * j < N; j ++)
			prime[i * j] = 1;
	}
}
int pre_sum[N];
void init()
{
	memset(pre_sum, 0, sizeof(pre_sum));
	for (int i = 3; i < N; i += 2)
		if (!prime[i] && !prime[(i + 1) / 2])
			pre_sum[i] = 1;
	for (int i = 1; i < N; i++)
		pre_sum[i] += pre_sum[i - 1];
}
int main()
{
	f();
	init();
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int l, r;
			cin >> l >> r;
			cout << pre_sum[r] - pre_sum[l - 1] << endl;
		}
	}
}