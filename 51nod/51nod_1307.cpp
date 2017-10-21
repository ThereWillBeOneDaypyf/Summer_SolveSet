#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int tar;

struct Edge
{
	int v,id,c;
};
vector<Edge>G[N];
int sz[N];
int x[N];
bool dfs(int u)
{
	sz[u] = x[u];
	int flag = 1;
	for(auto temp : G[u])
	{
		int v = temp.v, id = temp.id,c = temp.c;
		if(id > tar)
			continue;
		flag &= dfs(v);
		sz[u] += sz[v];
		if(c < sz[v])
			return false;
	}
	return flag;
}
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		for(int i = 0;i<N;i++)
			G[i].clear();
		for(int i = 1;i<=n;i++)
		{
			int c,w,p;
			scanf("%d%d%d",&c,&w,&p);
			x[i] = w;
			p ++;
			G[p].push_back({i,i,c});
		}
		int l = 0, r = n;
		int ans = 0;
		while(l <= r)
		{
			tar = (l + r) / 2;
			if(dfs(0))
			{
				l = tar + 1;
				ans = max(ans,tar);
			}
			else
				r = tar - 1;
		}
		printf("%d\n",ans);
	}
}
