#include<bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		long long a, b;
		scanf("%lld%lld", &a, &b);
		printf("Case #%d:\n", ++ka);
		if (a == b)
		{
			printf("1\n%lld %lld\n", a, b);
		}
		else
		{
			printf("2\n");
			if (a > b)
				swap(a, b);
			printf("%lld %lld\n", a, b);
			printf("%lld %lld\n", b, a);
		}
	}
}