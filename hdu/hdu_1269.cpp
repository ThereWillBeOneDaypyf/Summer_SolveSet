#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

struct Edge
{
	int u,v,next;
}edge[N*2];

int head[N],dfn[N],low[N];
stack<int>st;
int instack[N];
int tot = 0,Index = 0;
int block = 0;
int n;
void init()
{
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(head,-1,sizeof(head));
	memset(instack,0,sizeof(instack));
	tot = 0,block = 0,Index = 0;
	while(!st.empty())
		st.pop();
}
void add_edge(int u,int v)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++ Index;
	st.push(u);
	instack[u] = 1;
	for(int i = head[u] ; ~i;i=edge[i].next)
	{
		int v = edge[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[v] , low[u]);
		}
		else if(instack[v])
			low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		int x;
		block ++;
		do
		{
			x = st.top();	
			instack[x] = 0;
			st.pop();
		}while(x != u);
	}
}
void solve()
{
	for(int i = 1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
}
int main()
{
	int m;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0)
			break;
		init();
		for(int i =0 ;i<m;i++)
		{
			int u,v;
			cin >> u >> v;
			add_edge(u,v);
		}
		solve();
		if(block <= 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
