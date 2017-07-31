#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

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
	dep[u] = d;
	fa[u][0] = Fa;
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
	for(int i = 20;i>=0;i--)
		if(fa[x][i] != fa[y][i])
			x = fa[x][i] , y = fa[y][i];
	return fa[x][0];
}
int s[3];
int p[3];
int dis(int u,int v)
{
	return dep[u] + dep[v] - 2 * dep[lca(u,v)];
}
int solve()
{
	for(int i = 0;i<3;i++)
	{
		scanf("%d",s+i);
		p[i] = i;
	}
	int ans = 0;
	do
	{
		int a = s[p[0]],b = s[p[1]], c = s[p[2]];
		int res = dis(a,c) + dis(b,c) - dis(a,b);
		res /= 2;
		res ++;
		ans = max(ans,res);
	}while(next_permutation(p,p+3));
	return ans;
}
int main()
{
	int n,q;
	while(scanf("%d%d",&n,&q) == 2)
	{
		init();
		for(int i = 2;i<=n;i++)
		{
			int u;
			scanf("%d",&u);
			add_edge(u,i);
			add_edge(i,u);
		}
		dfs(1,1,0);
		for(int i = 0;i<q;i++)
			printf("%d\n",solve());
	}
}
