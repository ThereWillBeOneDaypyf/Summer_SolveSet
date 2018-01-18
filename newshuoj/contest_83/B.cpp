#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int fa[N];
int deg[N];

void init()
{
	memset(deg, 0, sizeof(deg));
	for (int i = 0; i < N; i++)
		fa[i] = i;
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
bool judge(int n)
{
	for (int i = 1; i <= n; i ++)
	{
		if (find(i) != find(1) && deg[i])
			return false;
		if (deg[i] % 2)
			return false;
	}
	return true;
}
int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		init();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			merge(u, v);
			deg[u] ++, deg[v] ++;
		}
		if (judge(n))
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}