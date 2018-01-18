#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

long long Map[N][N];

int main()
{
	int n,m;
	while(cin >> n >> m && (n || m))
	{
		memset(Map,-1,sizeof(Map));
		for(int i = 0;i < m;i++)
		{
			int u,v;
			long long d;
			cin >> u >> v >> d;
			if(Map[u][v] == -1)
				Map[u][v] = Map[v][u] = d;
			else
				Map[u][v] = min(Map[u][v],d),
					Map[v][u] = min(Map[v][u],d);
		}
		for(int k = 0;k < n;k++)
		{
			for(int i = 0;i < n;i++)
			{
				if(i == k)
					continue;
				for(int j = 0;j < n;j++)
				{
					if(j == k || j == i)
						continue;
					if(Map[i][k] != -1 && Map[k][j] != -1)
					{
						if(Map[i][j] == -1)
							Map[i][j] = Map[i][k] + Map[k][j];
						else
							Map[i][j] = min(Map[i][j],Map[i][k] + Map[k][j]);
					}
				}
			}
		}
		long long ans = 0;
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(i == j)
					continue;
				ans = max(ans,Map[i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
