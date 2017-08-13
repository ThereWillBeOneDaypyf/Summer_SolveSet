#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;


vector<int>G[N];
int sz[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
}
void add_edge(int u, int v)
{
	G[u].push_back(v);
}
void dfs(int u, int fa)
{
	sz[u] = 0;
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		sz[u] ++;
		dfs(v, u);
	}
}
double get_ans(int u, int fa, double k, double len)
{
	if (!sz[u])
		return (double)k * len;
	double ans = 0;
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		ans += get_ans(v, u, k * (double)(1.0 / sz[u]), len + 1.0);
	}
	return ans;
}
int main()
{
	int n;
	while (cin >> n)
	{
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			add_edge(u, v), add_edge(v, u);
		}
		dfs(1, 1);
		printf("%f\n", get_ans(1, 1, 1, 0));
	}
}