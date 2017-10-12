#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Edge
{
	int u, v, d;
};

int fa[N];
vector<Edge>edge;
void init()
{
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
	if (a != b)
		fa[a] = b;
}
long long Kruskal(int flag, int tar)
{
	init();
	int Max = 0;
	long long ans = 0;
	for (auto temp : edge)
	{
		int u = temp.u, v = temp.v, d = temp.d;
		if (flag && d > tar)
			continue;
		if (find(u) != find(v))
		{
			merge(u, v);
			ans += d;
			Max = max(Max, d);
		}
	}
	if (!flag) return Max;
	return ans;
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		edge.clear();
		for (int i = 0; i < m; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			edge.push_back({u, v, d});
		}
		sort(edge.begin(), edge.end(), [](Edge a, Edge b) {return a.d < b.d;});
		int tar = Kruskal(0, 0);
		sort(edge.begin(), edge.end(), [](Edge a, Edge b) {return a.d > b.d;});
		printf("%lld\n", Kruskal(1, tar));
	}
}
