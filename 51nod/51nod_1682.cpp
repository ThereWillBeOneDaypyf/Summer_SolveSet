#include<bits/stdc++.h>
using namespace std;

const int N = 8010;

int a[N];
int Left[N];
int Right[N];
int sum[N * 2];
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (int i = 1; i <= n; i++)
		{
			int ans = 0;
			memset(Left, 0, sizeof(Left));
			memset(Right, 0, sizeof(Right));
			memset(sum, 0, sizeof(sum));
			for (int j = i - 1; j >= 1; j--)
			{
				if (a[j] > a[i])
					Left[j] ++;
				else
					Left[j] --;
				Left[j] += Left[j + 1];
				sum[Left[j] + n] ++;
				if (Left[j] == 0)
					ans ++;
			}
			for (int j = i + 1; j <= n; j++)
			{
				if (a[j] > a[i])
					Right[j] ++;
				else
					Right[j] --;
				Right[j] += Right[j - 1] ;
				ans += sum[n - Right[j]];
				if (Right[j] == 0)
					ans ++;
			}
			if (i != 1)
				printf(" ");
			printf("%d", ans + 1);
		}
		printf("\n");
	}
}