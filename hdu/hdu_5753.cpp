#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3 + 7;

double a[N];

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf", a + i);
		if (n == 1)
		{
			printf("%.8lf\n", a[0]);
			continue;
		}
		double ans = a[0] / 2.0 + a[n - 1] / 2.0;
		for (int i = 1; i < n - 1; i++)
			ans += a[i] / 3.0;
		printf("%.8f\n", ans);
	}
}