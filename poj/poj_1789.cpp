#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

struct Edge
{
	int u, v, d;
	bool operator < (const Edge &rhs) const
	{
		return d < rhs.d;
	}
} edge[N * 2];

int fa[N];
int tot = 0;
void init()
{
	for (int i = 0; i < N; i++)
		fa[i] = i;
	tot = 0;
}
void add_edge(int u, int v, int d)
{
	edge[tot] = {u, v, d};
	tot ++ ;
}
int find(int x)
{
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (fa[a] != fa[b])
		fa[a] = fa[b];
}
int kruskal()
{
	sort(edge, edge + tot);
	int ans = 0;
	for (int i = 0; i < tot; i++)
	{
		if (find(edge[i].u) != find(edge[i].v))
		{
			merge(edge[i].u, edge[i].v);
			ans += edge[i].d;
		}
	}
	return ans;
}
vector<string>s;
int dis(int i, int j)
{
	int cnt = 0;
	for (int l = 0; l < s[i].length(); l++)
		if (s[i][l] != s[j][l])
			cnt ++;
	return cnt;
}
int main()
{
	int n;
	while (cin >> n && n)
	{
		init();
		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			s.push_back(str);
		}
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i + 1; j < s.size(); j++)
			{
				add_edge(i, j, dis(i, j));
			}
		}
		cout << "The highest possible quality is 1/" << kruskal() << "." << endl;
	}
}