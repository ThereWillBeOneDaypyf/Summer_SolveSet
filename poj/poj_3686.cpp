#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x7ffffff

const int N = 3e3;
int Map[N][N];
int cx[N],cy[N];
int visx[N],visy[N],pre[N];
int slack[N];
int un,vn;
bool dfs(int u)
{
	visx[u] = 1;
	for(int v = 1;v<=vn;v++)
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
			slack[v] = min(slack[v] , cx[u] + cy[v] - Map[u][v]);
	}
	return false;
}
int km()
{
	memset(pre,-1,sizeof(pre));
	memset(cy,0,sizeof(cy));
	for(int i = 0;i<N;i++)
		cx[i] = -INF;
	for(int i = 1;i<=un;i++)
		for(int j = 1;j<=vn;j++)
			cx[i] = max(cx[i],Map[i][j]);	
	for(int i = 1;i<=un;i++)
	{
		for(int j = 1;j<=vn;j++)	
			slack[j] = INF;
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(dfs(i))
				break;
			int d = INF;
			for(int j = 1;j<=vn;j++)
				if(!visy[j])
					d = min(d,slack[j]);
			for(int j = 1;j<=un;j++)
				if(visx[j])
					cx[j] -= d;
			for(int j = 1;j<=vn;j++)
				if(visy[j])
					cy[j] += d;
				else
					slack[j] -= d;
		}
	}
	int ans = 0;
	for(int i = 1;i<=vn;i++)
		if(pre[i] != -1)
			ans += Map[pre[i]][i];
	return -ans;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		un = n;
		vn = n*m;
		for(int i = 1;i<=n;i++)
		{
			int cnt = 0;
			for(int j = 1;j<=m;j++)
			{
				int x;
				cin >> x;
				for(int k = 1;k<=n;k++)
				{
					Map[i][++cnt] = -x * k;
				}
			}
		}		
		int res = km();
		printf("%.6f\n",1.0 * res / un);
	}
	return 0;
}

