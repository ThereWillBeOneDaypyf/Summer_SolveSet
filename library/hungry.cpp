#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e3;
int Map[N][N];
int clr[N];
int vis[N];
int pre[N];
int n;
bool make_clr(int u,int flag)
{
	if(clr[u] == -1)
		clr[u] = flag;
	else
		return clr[u] == flag;
	for(int i = 1;i<=n;i++)
	{
		if(Map[u][i])
		{
			if(!make_clr(i,!flag))
				return false;
		}
	}
	return true;
}
bool judge_graph()
{
	memset(clr,-1,sizeof(clr));
	for(int i = 1;i<=n;i++)
	{
		if(clr[i] == -1)
			if(!make_clr(i,0))
				return false;
	}
	return true;
}
bool dfs(int u)
{
	for(int v = 1;v<=n;v++)
	{
		if(Map[u][v] && !vis[v] && !clr[v])
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
	for(int i = 1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(clr[i] && dfs(i))
			ans ++;
	}
	return ans;
}

int main()
{
	int m;
	while(cin >> n >> m)
	{
		memset(Map,0,sizeof(Map));
		for(int i = 0;i<m;i++)
		{
			int u,v;
			cin >> u >> v;
			Map[u][v] = Map[v][u] = 1;
		}
		if(!judge_graph())
			cout << "No" << endl;
		else
			cout << hungry() << endl;
	}
}
