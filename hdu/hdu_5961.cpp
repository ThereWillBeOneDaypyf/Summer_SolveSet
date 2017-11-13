#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> G[N],V[N];
bool Map[2500][2500];
int dis[N];
int ok[N];
bool judge(int n)
{
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			if(i != j && !Map[i][j])
				return false;
	return true;
}
void bfs(int s,int n,vector<int>tar[])
{
	queue<int> q;
	q.push(s);
	memset(ok,0,sizeof(ok));
	for(int i = 1;i<=n;i++)
		dis[i] = 1e9;
	dis[s] = 0;
	ok[s] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v : tar[u])
		{
			if(ok[v])
				continue;
			dis[v] = dis[u] + 1;
			q.push(v);
			ok[v] = 1;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i = 0;i<N;i++)
			G[i].clear(),V[i].clear();
		int n;
		scanf("%d",&n);
		memset(Map,0,sizeof(Map));
		char x[3000];
		for(int i = 1;i<=n;i++)
		{
			scanf("%s",x + 1);
			for(int j = 1;j<=n;j++)
			{
				if(x[j] != '-')
				{
					Map[i][j] = 1;
					Map[j][i] = 1;
				}
				if(x[j] == 'P')
				{
					G[i].push_back(j);
				}
				else if(x[j] != '-')
				{
					V[i].push_back(j);
				}
			}
		}
		if(judge(n))
		{
			int flag = 1;
			for(int i = 1;i<=n;i++)
			{
				bfs(i,n,G);
				//cout << i << " *************** " << endl;
				for(int j = 1;flag && j<=n;j++)
				{
				//	cout << dis[j] << " ";
					if(dis[j] > 1 && dis[j] != 1e9)
					{
						flag = 0;
						break;
					}
				}
				//cout << endl;
			}
			for(int i = 1;i<=n;i++)
			{
				bfs(i,n,V);
				for(int j = 1;flag && j <= n;j++)
				{
					if(dis[j] > 1 && dis[j] < 1e9)
					{
						flag = 0;
						break;
					}
				}
			}
			if(flag)
				printf("T\n");
			else
				printf("N\n");
		}
		else
			printf("N\n");
	}
}
