#include<iostream>
#include<cstring>
#include<queue>
#define N 210
#define inf 0xffffff
using namespace std;
int m,n,mark[N][N],dis[N][N][2],dir[4][2]={1,0, 0,1, -1,0, 0,-1},flag;
char s[N][N];
struct node{
	int x,y,step;
};
bool judge(int x,int y)
{
	if(x>=0 && x<m && y>=0 && y<n && s[x][y]!='#' && mark[x][y]==0)
		return 1;
	return 0;
}
void bfs(int x,int y)
{
	int k;
	queue<node>q;
	node cur,next;
	cur.x=x;cur.y=y;cur.step=0;
	mark[x][y]=1;
	q.push(cur);
	while(!q.empty())
	{
		cur=q.front();
		q.pop();
		next.step=cur.step+1;
		for(k=0;k<4;k++)
		{
			next.x=x=cur.x+dir[k][0];
			next.y=y=cur.y+dir[k][1];
			if(judge(x,y))
			{
				mark[x][y]=1;
				if(s[x][y]=='@')
					dis[x][y][flag]=next.step;
				q.push(next);
			}
		}
	}
}

int main()
{
	int i,j,min;
	while(scanf("%d %d",&m,&n)!=-1)
	{
		min=inf;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				dis[i][j][0]=dis[i][j][1]=inf;

		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(s[i][j]=='Y')
				{
					flag=0;
					memset(mark,0,sizeof(mark));
					bfs(i,j);
				}
				else if(s[i][j]=='M')
				{
					flag=1;
					memset(mark,0,sizeof(mark));
					bfs(i,j);
				}
			}
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				if(s[i][j]=='@' && min>dis[i][j][0]+dis[i][j][1])
					min=dis[i][j][0]+dis[i][j][1];
		printf("%d\n",min*11);
	}
	return 0;
}
