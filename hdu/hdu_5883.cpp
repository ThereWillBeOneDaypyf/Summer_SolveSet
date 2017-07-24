#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

vector<int>G[N];

int a[N];
int vis[N];
int deg[N];
int n;
void init()
{
	for(int i =0 ;i<N;i++)
		G[i].clear();
	memset(vis,0,sizeof(vis));
	memset(deg,0,sizeof(deg));
}
void dfs(int u,int fa)
{
	vis[u] = 1;
	for(int i = 0;i<G[u].size();i++)
	{
		int v = G[u][i];
		if(v == fa || vis[v])
			continue;
		dfs(v,u);
	}
}
int euler()
{
	int cnt = 0;
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i])
		{
			dfs(i,i);
			cnt ++;
		}
		if(cnt >= 2)
			return 0;
	}
	cnt = 0;
	for(int i = 1;i<=n;i++)
	{
		if(deg[i] % 2)
			cnt ++;
		if(cnt > 2)
			return 0;
	}
	if(cnt == 0)
		return 2;
	else if(cnt == 2)
		return 1;
	else
		return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int m;
		scanf("%d%d",&n,&m);
		init();
		int ans = 0;
		for(int i = 1;i<=n;i++)
			scanf("%d",a+i);
		for(int i = 0;i<m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
			deg[u] ++;
			deg[v] ++;
		}
		for(int i = 1;i<=n;i++)
		{
			int cnt = (deg[i] + 1) / 2;
			if(cnt % 2)
				ans ^= a[i];
		}
		int flag = euler();
		if(!flag)
			printf("Impossible\n");
		else if(flag == 1)
			printf("%d\n",ans);
		else
		{
			int Max = 0;
			for(int i = 1;i<=n;i++)
				Max = max(Max,ans ^ a[i]);
			printf("%d\n",Max);
		}
	}	
}
