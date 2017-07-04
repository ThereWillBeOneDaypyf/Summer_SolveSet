#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

struct Edge
{
	int u,v;
	int next;
}edge[N*2];

int instack[N],belong[N],dfn[N],low[N];
int head[N];
int vis[N];
int pre[N];
stack<int>st;
vector<int>G[N];
int tot = 0,block = 0,Index = 0;

int n;

void init()
{
	memset(instack,0,sizeof(instack));
	memset(belong,0,sizeof(belong));
	memset(dfn,0,sizeof(belong));
	memset(low,0,sizeof(low));
	memset(head,-1,sizeof(head));
	memset(belong,0,sizeof(belong));
	while(!st.empty())
		st.pop();
	for(int i = 0;i<N;i++)
		G[i].clear();
	tot = 0;
	block = 0;
	Index = 0;
}
void add_edge(int u,int v)
{
	edge[tot].u = u,edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++Index;
	instack[u] = 1;
	st.push(u);
	for(int i = head[u];~i;i=edge[i].next)
	{
		int v = edge[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[v],low[u]);
		}
		else if(instack[v])
			low[u] = min(low[u],dfn[v]);
	}
	int x ;
	if(dfn[u] == low[u])
	{
		block++;
		do
		{
			x = st.top();
			st.pop();
			instack[x] = 0;
			belong[x] = block;
		}while(x != u);
	}
}
void solve()
{
	for(int i = 1;i<=n;i++)
	{
		if(!dfn[i])
			tarjan(i);
	}	
}
bool dfs(int u)
{
	for(int i = 0;i<G[u].size();i++)
	{
		int v = G[u][i];
		if(!vis[v])
		{
			vis[v] = 1;
			if(pre[v] == -1 || dfs(pre[v]))
			{
				pre[v] = u;
				return true;
			}
		}
	}
	return false;	
}
int hungry()
{
	int ans = 0;
	memset(pre,-1,sizeof(pre));
	for(int i = 1;i<=block;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			ans ++;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int m;
		scanf("%d%d",&n,&m);
		init();
		for(int i = 0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}	
		solve();
		for(int i =0 ;i<m;i++)
		{
			int u = edge[i].u,v = edge[i].v;
			if(belong[u] != belong[v])
				G[belong[u]].push_back(belong[v]);
		}
		cout << block - hungry() << endl;
	}
	return 0;
}
