#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

int a[N];
int vis[N];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);
		int ans = 1;
		for (int i = n - 2 ; i >= 0; i--)
			if (a[i + 1] - a[i] <= k)
				ans ++;
			else
				break;
		printf("%d\n", ans);
	}
}