#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define eps 1e-4
#define PI 3.1415926535
int main()
{
	double R;
	int n;
	int ka = 0;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%d", &R, &n);
		double l = 0, r = R;
		int cnt = 1000;
		while (cnt--)
		{
			double mid = (l + r) / 2;
			double	angle = asin(mid / (R - mid));
			double sum = angle * 2.0 * (double)n;
			if (sum > 2.0 * PI)
				r = mid;
			else
				l = mid;
		}
		printf("Scenario #%d:\n%.3lf\n\n", ++ka, l);
	}
}