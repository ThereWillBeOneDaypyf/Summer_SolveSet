#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


struct Edge
{
	int u,v;
	int next;
}edge[100000];

int head[100000];
int vis[10000];
int deg[10000];
int tot = 0;
int n,m;


void init()
{
	memset(head,-1,sizeof(head));
	memset(deg,0,sizeof(deg));
	memset(vis,0,sizeof(vis));
	tot = 0;
}
void add_edge(int u,int v)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void dfs(int u)
{
	vis[u] = 1;
	for(int i = head[u] ; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		if(vis[v])
			continue;
		dfs(v);
	}
}
bool judge()
{
	int cnt = 0;
	for(int i = 1 ;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i);	
			cnt ++;
			if(cnt > 1)
				return false;
		}
	}
	for(int i = 1;i<=n;i++)
		if(deg[i] % 2)
			return false;
	return true;
}
int main()
{
	while(cin >> n && n)
	{
		cin >> m;
		init();
		for(int i = 0;i<m;i++)
		{
			int u,v;
			cin >> u >> v;
			add_edge(u,v);
			add_edge(v,u);
			deg[u] ++,deg[v]++;
		}
		if(judge())
			cout << 1 << endl;
		else
			cout << 0 << endl;	
	}
}
