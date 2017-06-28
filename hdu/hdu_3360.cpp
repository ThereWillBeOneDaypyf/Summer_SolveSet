#include<bits/stdc++.h>
using namespace std;

const int N = 3005;

int xdir[12] = {-1,-2,-2,-1,1,2,2,1,-1,0,1,0};
int ydir[12] = {-2,-1,1,2,2,1,-1,-2,0,1,0,-1};

vector<int>G[N];
int a[N][N];
int un,vn;
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
	int ans = 0;
	memset(pre,-1,sizeof(pre));
	for(int i  = 0;i<un;i++)
	{
		for(int j = 0;j<vn;j++)
		{
			int t = (i + j) % 2;
			if(t)
			{
				memset(vis,0,sizeof(vis));
				if(dfs(i*vn+j))
					ans ++;
			}
		}
	}
	return ans;
}
int main()
{
	int n,m;
	int ka = 0;
	while(scanf("%d%d",&un,&vn)==2)
	{
		if(un == 0 && vn == 0)
			break;
		n = un , m = vn;
		for(int i = 0 ;i<=un*vn;i++)
			G[i].clear();
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				int t = (i + j)%2;
				if(a[i][j] == -1)
					continue;
				for(int k = 0;k<12;k++)
				{
					int cur = 1 << k;
					if((cur & a[i][j]))
					{
						int tx = i + xdir[k];
						int ty = j + ydir[k];
						if(tx < 0|| ty < 0 || tx >= n || ty >= m || a[tx][ty] == -1)
							continue;
						if(t) G[i*vn+j].push_back(tx*vn+ty);
						else
							G[tx*vn+ty].push_back(i*vn+j);
					}
				}
			}
		}
		printf("%d. %d\n",++ka,hungry());
	}	
}
