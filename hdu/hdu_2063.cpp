#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

vector<int>G[10000];
int n,m,k;
int pre[10000];
int vis[10000];

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
	memset(pre,-1,sizeof(pre));
	int ans = 0;
	for(int i = 1;i<= n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			ans ++;
	}
	return ans;
}
int main()
{
	while(cin >> k && k)
	{
		cin >> n >> m;
		for(int i = 1;i<=n;i++)
			G[i].clear();		
		for(int i = 0;i<k;i++)
		{
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
		}
		cout << hungry() << endl;
	}
}
