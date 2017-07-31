#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

struct Edge
{
	int u,v,next;
}edge[N*2];

int head[N];
int fa[N][21],dep[N];
int tot = 0;
void init()
{
	memset(head,-1,sizeof(head));
	tot = 0;
}
void add_edge(int u,int v)
{
	edge[tot] = {u,v,head[u]};
	head[u] = tot ++;
}
void dfs(int u,int Fa,int d)
{
	dep[u] = d,fa[u][0] = Fa;
	for(int i = 1;i<=20;i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i = head[u];~i;i=edge[i].next)
	{
		int v = edge[i].v;
		if(v == Fa)
			continue;
		dfs(v,u,d+1);
	}
}
int lca(int x,int y)
{
	if(dep[x] < dep[y])
		swap(x,y);
	for(int i = 20;i>=0;i--)
		if(dep[fa[x][i]] >= dep[y])
			x = fa[x][i];
	if(x == y)
		return x;
	for(int i =20;i>=0;i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while(T--)
	{
		int n;
		cin >> n;
		init();
		for(int i = 0;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(0,0,0);
		int q;
		cin >> q;
		cout << "Case " << ++ ka << ":" << endl; 
		for(int i = 0;i<q;i++)
		{
			int u,v;
			cin >> u >> v;
			if(i)
				cout << " ";
			cout << lca(u,v);
		}	
		cout << endl;
	}	
}
