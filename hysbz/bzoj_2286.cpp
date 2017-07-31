#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
const int INF = 1e9;
const int N = 5e5 + 10;

struct Edge
{
	int u,v;
	long long d;
	int next;
}edge[N*2],vedge[N*2];
int fa[N][21];
int head[N],vhead[N];
int dfn[N],L[N],R[N];
int dep[N];
long long dis[N];
int tot = 0,vtot = 0,Index = 0;
void init()
{
	tot = 0;
	Index = 0;
	memset(head,-1,sizeof(head));
	for(int i = 0;i<250005;i++)
		dis[i] = INF;
}
void vinit()
{
	vtot = 0;
	memset(vhead,-1,sizeof(vhead));
}
void add_edge(int u,int v,int d)
{
	edge[tot].u = u,edge[tot].v = v,edge[tot].d = d;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void add_vedge(int u,int v,int d)
{
	vedge[vtot].u = u,vedge[vtot].v = v,vedge[vtot].d = d;
	vedge[vtot].next = vhead[u];
	vhead[u] = vtot ++;
}
void dfs(int u,int Fa,int d)
{
	dep[u] = d,fa[u][0] = Fa;
	dfn[u] = L[u] = ++Index;
	for(int i = 1;i<=20;i++)
		fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int i = head[u];~i;i=edge[i].next)
	{
		int v = edge[i].v;
		if(v == Fa)
			continue;
		dis[v] = min(dis[u],edge[i].d);
		dfs(v,u,d+1);
	}
	R[u] = Index;
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
			x = fa[x][i],y = fa[y][i];
	return fa[x][0];
}
int key[N];
bool cmp(int u,int v)
{
	return dfn[u] < dfn[v];
}
bool check(int x,int y)
{
	return 	L[x] <= L[y] && R[y] <= R[x];
}
int ine[N];
int is_key[N];
int stk[N];
int tar[N];
int build_vtree(int k)
{
	int len = 0;
	memset(ine,0,sizeof(ine));
	memset(is_key,0,sizeof(is_key));
	vinit();
	int root = 0;
	for(int i = 0;i<k;i++)
	{
		scanf("%d",key+i);	
		tar[len++] = key[i];
		is_key[key[i]] = 1;
	}
	for(int i = 1;i<k;i++)
		tar[len++] = lca(key[i],key[i-1]);
	tar[len++] = 1;
	sort(tar,tar+len,cmp);
	k = unique(tar,tar+len) - tar;
	int top = 0;
	for(int i = 0;i<k;i++)
	{
		while(top && !check(stk[top],tar[i]))	
			top--;
		if(!top) root = tar[i];
		else if(lca(stk[top],tar[i]) == stk[top] && ine[stk[top]] && is_key[stk[top]])
			continue;
		else
		{
			int s = stk[top],t = tar[i];
			add_vedge(s,t,dis[t]);
			ine[t] = 1;
		}
		stk[++top] = tar[i];
	}
	root = 1;
	return root;
}
long long dp[N];
void tree_up(int u)
{
	dp[u] = dis[u];
	long long temp = 0;
	for(int i = vhead[u];~i;i=vedge[i].next)
	{
		tree_up(vedge[i].v);
		temp += dp[vedge[i].v];
	}	
	if(!temp)
		dp[u] = dis[u];
	else dp[u] = min(dp[u],temp);
}
void solve()
{
	int k;
	scanf("%d",&k);
	int root = build_vtree(k);
	memset(dp,0,sizeof(dp));
	tree_up(root);	
	printf("%lld\n",dp[root]);
}
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		init();
		for(int i = 1;i<n;i++)
		{
			int u,v;
			long long d;
			scanf("%d%d%lld",&u,&v,&d);
			add_edge(u,v,d);
			add_edge(v,u,d);
		}
		dfs(1,1,0);
		int q;
		scanf("%d",&q);
		for(int i = 0;i<q;i++)
			solve();
	}
}
