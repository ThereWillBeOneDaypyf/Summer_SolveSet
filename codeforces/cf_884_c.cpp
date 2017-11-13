#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int clr[N];
int sz[N];
vector<int> G[N];
int tot = 0;
int sum = 0;
void init()
{
	memset(clr, -1, sizeof(clr));
	for (int i = 0; i < N; i++)
		G[i].clear();
}
void dfs(int u, int flag)
{
	if (clr[u] != -1)
		return;
	clr[u] = flag;
	sum ++;
	for (auto v : G[u])
		dfs(v, flag);
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		init();
		for (int i = 1; i <= n; i++)
		{
			int p;
			scanf("%d", &p);
			G[i].push_back(p);
		}
		for (int i = 1; i <= n; i++)
		{
			if (clr[i] == -1)
			{
				sum = 0;
				dfs(i, ++tot);
				sz[tot] = sum;
			}
		}
		if (tot == 1)
			printf("%lld\n", 1LL * n * n);
		else
		{
			sort(sz + 1, sz + tot + 1, [](int a, int b) {return a > b;});
			long long ans = 1LL * (sz[1] + sz[2]) * (sz[1] + sz[2]);
			for (int i = 3; i <= tot ; i++)
				ans += 1LL * sz[i] * sz[i];
			printf("%lld\n", ans);
		}
	}
}