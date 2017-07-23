#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e6 + 8;

int a[N];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, s;
		scanf("%d%d", &n, &s);
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		int l = 0, r = 0;
		int cur_sum = 0;
		int ans = INF;
		while (r <= n && l <= r)
		{
			if (cur_sum < s)
				cur_sum += a[r++];
			else
			{
				ans = min(ans , r - l);
				cur_sum -= a[l++];
			}
		}
		if (ans == INF)
			printf("%d\n", 0);
		else
			printf("%d\n", ans);
	}
}