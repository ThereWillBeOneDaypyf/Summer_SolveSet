#include<bits/stdc++.h>
#define ll long long
#define N 10000005
using namespace std;
int n, p, tot;
int phi[N], pri[1000005];
bool mark[N];
ll ans, sum[N];
void getphi() // 打表到***n***
{
	phi[1] = 1;
	tot = 0;
	memset(mark, 0, sizeof(mark));
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) {phi[i] = i - 1; pri[++tot] = i;}
		for (int j = 1; j <= tot; j++)
		{
			int x = pri[j];
			if (i * x > n)break;
			mark[i * x] = 1;
			if (i % x == 0) {phi[i * x] = phi[i] * x; break;}
			else phi[i * x] = phi[i] * phi[x];
		}
	}
}
int main()
{
	while (scanf("%d", &n) == 1)
	{
		getphi();
		ans = 0;
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + phi[i];
		for (int i = 1; i <= tot; i++)
			ans += sum[n / pri[i]] * 2 - 1;
		printf("%lld\n", ans);
	}
}
