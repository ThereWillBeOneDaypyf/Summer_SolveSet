#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

int n,m;
vector<pair<int,bool> > G[N];
int vis[N];
int deg[N];
int flag = 0,ok = 0;
void init()
{
	for(int i = 0;i < N;i++)
		G[i].clear();
	memset(vis,0,sizeof(vis));
	flag = 0,ok = 0;
}
bool topu()
{
	memset(deg,0,sizeof(deg));
	for(int i = 1;i <= n;i++)
	{
		for(auto &v : G[i])
		{
			if(v.second)
				continue;
			deg[v.first] ++;
		}
	}
	for(int k = 0;k < n;k++)
	{
		int cnt = 0;
		for(int i = 1;i <= n;i++)
		{
			if(deg[i] == 0)
			{
				cnt = 1;
				deg[i] --;
				for(auto &v : G[i])
				{
					if(v.second)
						continue;
					deg[v.first] --;
				}
				break;
			}
		}
		if(!cnt)
			return false;
	}
	return true;
}
bool dfs(int u)
{
	if(vis[u] == 1)
		return false;
	if(vis[u] == -1)
	{
		vis[u] = 1;
		return true;
	}
	vis[u] = -1;
	for(auto &v : G[u])
	{
		if(dfs(v.first))
		{
			v.second = true;
			if(topu())
				flag = 1;
			v.second = false;
			vis[u] = 1;
			return true;
		}
	}
	vis[u] = 1;
	return false;
}
int main()
{
	ios :: sync_with_stdio(false);
	while(cin >> n >> m)
	{
		init();
		for(int i = 0;i < m;i++)
		{
			int u,v;
			cin >> u >> v;
			G[u].push_back(make_pair(v,false));
		}
		if(topu())
		{
			flag = 1;
			cout << "YES" << endl;
			continue;
		}
		else
			flag = 0;
		for(int i = 1;i <= n;i++)
		{
			if(dfs(i))
				break;
		}
		if(!flag)
			cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}
