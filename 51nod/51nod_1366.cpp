#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

const int N = 1e5;

vector<int>G[N];

int dis[N];
int vis[N];
void init()
{
	for(int i = 0;i<N;i++)
		G[i].clear();
}

int spfa(int s,int n)
{
	for(int i = 1;i<=n;i++)
		dis[i] = INF;
	dis[s] = 0;
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(auto v : G[u])
		{
			if(dis[v] > dis[u] + 1)
			{
				dis[v] = dis[u] + 1;
				if(!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	int Max = 0;
	for(int i = 1;i<=n;i++)
		Max = max(dis[i],Max);
	return Max;
}

int main()
{
//	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		int n,d;
		cin >> n >> d;
		init();
		char s[1000];
		for(int i =1;i<=n;i++)
		{
			scanf("%s",s + 1);
			for(int j = 1;j<=n;j++)
			{
				if(s[j] == 'Y')
					G[i].push_back(j);
			}
		}
		int Max = 0;
		for(int i = 1;i<=n;i++)
			Max = max(Max,spfa(i,n));
		if(Max >= INF)
			cout << -1 << endl;
		else
			cout << Max * d << endl;
	}
}
