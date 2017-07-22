#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5;

struct Node
{
	int w, s;
	bool operator < (const Node &rhs) const
	{
		return w - rhs.s < rhs.w - s;
	}
} a[N];

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &a[i].w, &a[i].s);
		sort(a + 1, a + n + 1);
		long long pre_sum = 0;
		long long ans = pre_sum - a[1].s;
		pre_sum += a[1].w;
		for (int i = 2; i <= n; i++)
		{
			ans = max(ans, pre_sum - a[i].s);
			pre_sum += a[i].w;
		}
		if (ans < 0)
			ans = 0;
		printf("%lld\n", ans);
	}
}