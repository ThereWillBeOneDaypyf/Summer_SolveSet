#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		long long sum = 0, t = 0;
		for (int i = 0; i < n; i++)
		{
			long long x;
			scanf("%lld", &x);
			t += max(-1 * x , x);
			sum += x * x;
		}
		t = t * t;
		sum = sum * n;
		sum -= t;
		long long G = __gcd(sum, (long long)n);
		printf("%lld/%d\n", sum / G, n / G);
	}
}