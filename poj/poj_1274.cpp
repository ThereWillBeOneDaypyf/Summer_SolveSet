#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;


//thanks to pyf ...
//thansk to qhl ...

const int N = 1e3 + 5;

vector<int>G[N];
int vis[N];
int pre[N];
int un,vn;

void init()
{
	for(int i = 0; i < N;i++)
		G[i].clear();
}
bool dfs(int u)
{
	for(int i = 0 ;i<G[u].size();i++)
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
	for(int i = 1;i<=un;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			ans ++;
	}
	return ans;
}
int main()
{
	while(cin >> un >> vn)
	{
		init();
		for(int i = 1;i<=un;i++)
		{
			int cnt = 0;
			cin >> cnt;
			for(int j=0;j<cnt;j++)
			{
				int x ;
				cin >> x;
				G[i].push_back(x);
			}
		}
		cout << hungry() << endl;
	}
}
