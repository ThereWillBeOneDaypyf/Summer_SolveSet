#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e3 + 8;

int Map[N][N];
int cx[N],cy[N];
int visx[N],visy[N],pre[N];
int slack[N];
int n,m;
bool dfs(int u)
{
	visx[u] = 1;
	for(int v = 1;v <= n;v++)
	{
		if(!visy[v] && cx[u] + cy[v] == Map[u][v])
		{
			visy[v] = 1;
			if(pre[v] == -1 || dfs(pre[v]))
			{
				pre[v] = u;
				return true;
			}
		}	
		else
			slack[v] = min(slack[v],cx[u] + cy[v] - Map[u][v]);
	}
	return false;
}
int km()
{
	for(int i = 0;i<N;i++)
		cx[i] = -INF;
	memset(cy,0,sizeof(cy));
	memset(pre,-1,sizeof(pre));
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			cx[i] = max(cx[i],Map[i][j]);
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
			slack[j] = INF;
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(dfs(i))
				break;
			int d = INF;
			for(int j = 1;j<=n;j++)
				if(!visy[j])
					d = min(d,slack[j]);
			for(int j = 1;j<=n;j++)
			{
				if(visx[j])
					cx[j] -= d;
				if(visy[j])
					cy[j] += d;
				else
					slack[j] -= d;
			}
		}
	}
	int res = 0;
	for(int i = 1;i<=n;i++)
	{
		if(pre[i] == -1 || Map[pre[i]][i] <= -INF)
			return -1;
		else
			res += Map[pre[i]][i];
	}
	return -res;
}
int main()
{
	while(cin >> n >> m)
	{
		for(int i = 0;i<N;i++)
			for(int j = 0;j<N;j++)
				Map[i][j] = -INF;
		for(int i = 0;i<m;i++)
		{
			int u,v,d;
			cin >> u >> v >> d;
			Map[u][v] = max(Map[u][v], -d);
		}
		cout << km() << endl;	
	}
	return 0;
}

