#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

int a[1000];
int q[N];
int prime[N];
int vis[N];
int cnt_prime = 0;
void f()
{
	memset(vis, 0, sizeof(vis));
	cnt_prime = 0;
	for (int i = 2; i < N; i++)
	{
		if (!vis[i])
		{
			prime[cnt_prime++] = i;
			for (int j = 2; i * j < N; j++)
				vis[j * i] = 1;
		}
	}
}
int cnt = 0 ;
int tot = 0;
void solve(int m)
{
	cnt = 0;
	for (int i = 2; i <= sqrt(m); i++)
	{
		if (m % i == 0)
		{
			a[cnt++] = i;
			while (m % i == 0)
				m /= i;
		}
	}
	if (m != 1)
		a[cnt ++] = m;
	tot = 0;
	q[tot++] = -1;
	for (int i = 0; i < cnt; i++)
	{
		int temp_j = tot;
		for (int j = 0; j < temp_j; j++)
		{
			q[tot ++] = - q[j] * a[i];
		}
	}
}
long long rongchi(int m)
{
	long long ans = 0;
	for (int i = 1; i < tot; i++)
	{
		ans += (long long)m / q[i];
	}
	return ans;
}

int main()
{
	int n, m;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		if (n > m)
			swap(n, m);
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			solve(i);
			ans += (m - rongchi(m));
		}
		printf("%lld\n", ans);
	}
	return 0;
}