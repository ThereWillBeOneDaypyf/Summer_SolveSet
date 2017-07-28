#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 25;
int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};
int vis[N][N];
char Map[N][N];
int n,m;
struct Node
{
	int x,y,step;
	Node(int _x,int _y,int _step) : x(_x),y(_y),step(_step){}
};
int bfs(int a,int b,int c,int d)
{
	queue<Node>q;
	memset(vis,0,sizeof(vis));	
	q.push(Node(a,b,0));
	q.push(Node(c,d,0));
	vis[a][b] = 1;
	vis[c][d] = 1;
	int ans = 0;
	while(!q.empty())
	{
		Node temp = q.front();
		q.pop();
		ans = max(ans,temp.step);
		for(int i = 0;i<4;i++)
		{
			int tx = temp.x + xdir[i];
			int ty = temp.y + ydir[i];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m || Map[tx][ty] != '#' || vis[tx][ty])
				continue;
			vis[tx][ty] = 1;
			q.push(Node(tx,ty,temp.step+1));
		}
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(Map[i][j] == '#' && !vis[i][j])
				return INF;
		}
	}
	return ans;
}
int solve()
{
	int ans = INF;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(Map[i][j] != '#')
				continue;
			for(int x = i;x<n;x++)
			{
				for(int y = 0;y<m;y++)
				{
					if(Map[x][y] != '#')
						continue;
					int tar = bfs(i,j,x,y);
					if(tar < ans)
						ans = tar;
				}
			}
		}
	}
	if(ans >= INF)
		return -1;
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	int ka = 0;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i = 0;i<n;i++)
			scanf("%s",Map[i]);
		printf("Case %d: %d\n",++ka,solve());
	}
}
