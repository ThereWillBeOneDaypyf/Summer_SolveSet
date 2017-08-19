#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 3e3+1;
bool Map[N][N];
int n;
int flag = 0;
void dfs1(int u,int d,int from)
{
	if(d == 3 && u == from)
		flag = 1;
	if(d == 3)
		return;
	for(int i = 1;i<=n;i++)
	{
		if(Map[u][i] == 1)
			dfs1(i,d+1,from);
	}
}
void dfs2(int u,int d,int from)
{
	if(d == 3 && u == from)
		flag = 1;
	if(d == 3)
		return;
	for(int i = 1;i<=n;i++)
	{
		if(Map[u][i] == 0 && i != u)
			dfs2(i,d+1,from);
	}
}
bool judge()
{
	flag = 0;
	for(int i = 1;i<=n;i++)
	{
		dfs1(i,0,i);
		if(flag)
			return false;
	}
	for(int i = 1;i<=n;i++)
	{
		dfs2(i,0,i);
		if(flag)
			return false;
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(Map,0,sizeof(Map));
		int x;
		for(int i = 1;i<=n;i++)
		{
			for(int j = i + 1;j<=n;j++)
			{
				scanf("%d",&x);
				Map[j][i] = Map[i][j] = x;
			}
		}
		if(n <= 6 && judge())
			printf("Great Team!\n");
		else
			printf("Bad Team!\n");
	}
}
