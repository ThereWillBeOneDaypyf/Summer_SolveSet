#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

struct Edge
{
	int u,v;
}edge[N*2];

int fa[N];
int deg[N];
int odd[N];
int cnt[N];
void init()
{
	memset(deg,0,sizeof(deg));
	memset(odd,0,sizeof(odd));
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i<N;i++)
		fa[i] = i;
}
int find(int x)
{
	if(x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x != y)
		fa[x] = fa[y];
}
int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		init();
		for(int i = 0;i<m;i++)
		{
			cin >> edge[i].u >> edge[i].v;
			deg[edge[i].u] ++;
			deg[edge[i].v] ++;
			merge(edge[i].u,edge[i].v);
		}
		for(int i = 1;i<=n;i++)
		{
			if(deg[i] % 2)
				odd[find(i)] ++;
			cnt[find(i)] ++;
		}
		int ans = 0;
		for(int i = 1;i<=n;i++)
		{
			if(cnt[i] <= 1)
				continue;
			else if(odd[i] == 0)
				ans ++;
			else if(odd[i] > 0)
				ans += odd[i] / 2;
		}
		cout << ans << endl;
	}
}
