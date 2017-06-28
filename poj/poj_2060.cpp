#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3+5;
vector<int>G[N];
int un,vn;
int vis[N];
int pre[N];


struct Node
{
	int st,et;
	int sx,sy,ex,ey;
}a[N];
void init()
{
	for(int i =0;i<N;i++)
		G[i].clear();
	memset(a,0,sizeof(a));
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
	int T;
	cin >> T;
	while(T--)
	{
		init();
		cin >> un;
		for(int i = 1; i<=un;i++)
		{
			int h,m;
			scanf("%d:%d",&h,&m);
			cin >> a[i].sx >> a[i].sy >> a[i].ex >> a[i].ey;
			a[i].st = h * 60 + m; 
			a[i].et = a[i].st + abs(a[i].sx - a[i].ex) + abs(a[i].sy - a[i].ey);
		}
		for(int i = 1 ;i<=un;i++)
		{
			for(int j =1 ;j<=un;j++)
			{
				if(i!=j && a[i].st > a[j].et + abs(a[j].ex - a[i].sx) + abs(a[j].ey - a[i].sy))
				{
					G[j].push_back(i);
				}
			}
		}
		cout << un - hungry() << endl;
	}	
	return 0;
}
