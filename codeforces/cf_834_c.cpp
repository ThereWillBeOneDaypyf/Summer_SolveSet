#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

int prime[N][30];
int cnt[N];
int vis[N];

void f()
{
	memset(cnt, 0, sizeof(cnt));
	for (int i = 2; i < N; i++)
	{
		if (!vis[i])
		{
			prime[i][cnt[i]++] = i;
			for (int j = 2; i * j < N; j++)
			{
				vis[i * j] = 1;
				prime[i * j][cnt[i * j] ++] = i;
			}
		}
	}
}
long long ac = 0;
bool judge(long long tar)
{
	long long l = 1, r = 1e6 + 10;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		long long res = mid * mid * mid;
		if (res == tar)
		{
			ac = mid;
			return true;
		}
		if (res < tar)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long a, b;
		scanf("%I64d%I64d", &a, &b);
		long long ans = a * b;
		if (judge(ans) && a % ac == 0 && b % ac == 0)
			puts("YES");
		else
			puts("NO");
	}
}