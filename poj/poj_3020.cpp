#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

char Map[100][100];
vector<int>G[N];
int pre[N];
int vis[N];
int n,m;
int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};

void init()
{
	for(int i = 0;i<N;i++)
		G[i].clear();
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
	for(int i =0 ;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			int t = (i + j) % 2;
			if(t)
			{
				memset(vis,0,sizeof(vis));
				if(dfs(i*m+j))
					ans++;
			}
		}
	}
	return ans;
}
int main()
{
	int T;
	cin >> T;
	while(cin >> n >> m)
	{
		init();
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cin >> Map[i][j];
			}
		}
		int cnt = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				if(Map[i][j] == 'o')
					continue;
				int t = (i+j) % 2;
				cnt ++;
				for(int k =0 ;k<4;k++)
				{
					int tx = i + xdir[k];
					int ty = j + ydir[k];
					if(tx < 0 || tx >= n || ty < 0 || ty >= m || Map[tx][ty] == 'o')
						continue;
					if(t)
						G[i*m+j].push_back(tx*m+ty);
					else
						G[tx*m+ty].push_back(i*m+j);
				}	
			}
		}
		cout << cnt - hungry() << endl;
	}
	return 0;
}
