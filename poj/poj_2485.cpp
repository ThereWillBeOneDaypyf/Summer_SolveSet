#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

struct Edge
{
	int u, v, d;
	int del, intree;
	int equal;
	bool operator < (const Edge &rhs) const
	{
		return d < rhs.d;
	}
} edge[N * 2];
int fa[N];
int n, m;
int first;
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
	a = find(a);
	b = find(b);
	if (fa[a] != fa[b])
		fa[a] = b;
}
int kruskal() //求一次最小生成树
{
	init();
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int u = edge[i].u , v = edge[i].v;
		if (find(u) != find(v))
		{
			ans = max(ans, edge[i].d);
			merge(u, v);
		}
	}
	return ans;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		memset(edge, 0, sizeof(edge)); // 不初始化大概会错。。
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int x;
				scanf("%d", &x);
				if (i == j)
					continue;
				edge[cnt].u = i, edge[cnt].v = j, edge[cnt].d = x;
				cnt ++;
			}
		}
		m = cnt ;
		sort(edge, edge + m);
		printf("%d\n", kruskal());

	}
}