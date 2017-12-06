#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 8;

int fa[N];
int c[N];
long long mc[N];
void init()
{
	for (int i = 0; i < N; i++)
		fa[i] = i, mc[i] = 1e18;
}
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (fa[a] != fa[b])
		fa[a] = fa[b];
}
int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		init();
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			merge(a, b);
		}
		for (int i = 1; i <= n; i++)
			mc[find(i)] = min(mc[find(i)], (long long)c[i]);
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			if (mc[i] <= 1e9)
				ans += mc[i];
		cout << ans << endl;
	}
}