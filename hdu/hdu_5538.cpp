#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

int Map[N][N];
int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
long long solve(int x,int y)
{
	long long res = 0;
	for(int i = 0;i<4;i++)
	{
		int tx = x + xdir[i];
		int ty = y + ydir[i];
		if(Map[tx][ty] < Map[x][y])
			res += Map[x][y] - Map[tx][ty];
	}
	return res + 1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		memset(Map,0,sizeof(Map));
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				scanf("%d",&Map[i][j]);
		long long ans = 0;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				if(Map[i][j])
					ans += solve(i,j);
			}
		}
		printf("%lld\n",ans);
	}
}
