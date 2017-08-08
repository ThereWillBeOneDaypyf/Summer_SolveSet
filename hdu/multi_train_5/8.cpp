#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


long long b[10000];
long long dp[10000];
long long C(int n, int m) //C(n,m) choose m from n
{
	long long ans = 1;
	int i, j;
	for (i = n - m + 1, j = 1; i <= n && j <= m; i++, j ++)
		ans *= (i / j);
	while (i <= n)
		ans *= i ++;
	while (j <= m)
		ans /= j ++;
	return ans;
}
int ans[10000];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= m; i++)
			scanf("%lld", b + i);
		int cnt = n;
		ans[0] = log2(b[0]);
		cnt -= ans[0];
		dp[0] = ans[0];
		vector<int>tar;
		for (int i = 0; i < ans[0]; i++)
			tar.push_back(0);
		for (int i = 1; i <= m; i++)
		{
			while (b[i] > 0)
			{
				tar.push_back(i);
				for (int j = i; j <= m; j++)
				{
					b[j] -= b[j - i];

				}
			}
		}
		for (int i = 0; i < tar.size(); i++)
		{
			if (i)
				printf(" ");
			printf("%d", tar[i]);
		}
		printf("\n");
	}
}