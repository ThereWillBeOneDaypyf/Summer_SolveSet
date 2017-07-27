#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

struct Node
{
	int f, j;
	bool operator < (const Node &rhs) const
	{
		return j * rhs.f > rhs.j * f;
	}
} a[N];

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		if (m == -1 && n == -1)
			break;
		for (int i = 0; i < n; i++)
			cin >> a[i].j >> a[i].f;
		sort(a, a + n);
		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (m > a[i].f)
			{
				m -= a[i].f;
				ans += a[i].j;
			}
			else
			{
				ans += (double)(1.0 * m * (1.0 * a[i].j / a[i].f));
				break;
			}
		}
		printf("%.3lf\n", ans);
	}
}