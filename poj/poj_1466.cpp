#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e4;

int n;
vector<int>G[N];
int pre[N];
int vis[N];

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
	for(int i = 0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			ans ++;
	}
	return ans;
}
int main()
{
	while(cin >> n)
	{
		for(int i = 0;i<n;i++)
		{
			int u,cnt;
			scanf("%d: (%d)",&u,&cnt);
			G[u].clear();
			for(int j = 0;j<cnt;j++)
			{
				int v;
				cin >> v;
				G[u].push_back(v);
			}
		}
		cout << n - hungry() / 2 << endl;
	}
}
