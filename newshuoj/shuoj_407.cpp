#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;

struct Edge
{
	int u,v,d;
	bool operator < (const Edge &rhs) const
	{
		return d < rhs.d;
	}
}edge[N];

int fa[N];
int m;
void init()
{
	for(int i =0;i<N;i++)
		fa[i] = i;
}
int find(int x)
{
	if(fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a,int b)
{
	a = find(a);
	b = find(b);
	if(fa[a] != fa[b])
		fa[a] = b;
}
int kruskal()
{
	init();
	sort(edge,edge+m);
	int ans = 0;
	for(int i = 0;i<m;i++)
	{
		int u = edge[i].u ,v = edge[i].v;
		int d = edge[i].d;
		if(find(u) != find(v))
		{
			ans += d;	
			merge(u,v);
		}
	}
	return ans;
}
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		m = n * (n-1) / 2;
		for(int i = 0;i<m;i++)
		{
			int u,v,d;
			scanf("%d%d%d",&u,&v,&d);
			edge[i].u = u,edge[i].v = v,edge[i].d = d;
		}
		cout << kruskal() << endl;
	}
}
