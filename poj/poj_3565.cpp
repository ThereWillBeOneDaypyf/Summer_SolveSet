#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define eps 1e-6
const int N = 1000;

struct Node
{
	double x,y;
}p[N],q[N];

double cx[N],cy[N];
int visx[N],visy[N];
double Map[N][N];
double slack[N];
int pre[N];
int n;
int un,vn;
double dis(Node a,Node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool dfs(int u)
{
	visx[u] = 1;
	for(int v = 1;v<=vn;v++)
	{
		double temp = cx[u] + cy[v] - Map[u][v];
		if(!visy[v] && temp <= eps)
		{
			visy[v] = 1;
			if(pre[v] == -1 || dfs(pre[v]))
			{
				pre[v] = u;
				return true;
			}
		}
		else
			slack[v] = min(slack[v],temp);
	}
	return false;
}
void km()
{
	memset(pre,-1,sizeof(pre));
	memset(cy,0,sizeof(cy));
	for(int i = 0;i<N;i++)
		cx[i] = -INF;
	for(int i = 1;i<=un;i++)
		for(int j = 1;j<=vn;j++)
			cx[i] = max(cx[i],Map[i][j]);	
	for(int i = 1;i<=un;i++)
	{
		for(int j = 1;j<=vn;j++)	
			slack[j] = INF;
		while(1)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(dfs(i))
				break;
			double d = INF;
			for(int j = 1;j<=vn;j++)
				if(!visy[j])
					d = min(d,slack[j]);
			for(int j = 1;j<=un;j++)
				if(visx[j])
					cx[j] -= d;
			for(int j = 1;j<=vn;j++)
				if(visy[j])
					cy[j] += d;
				else
					slack[j] -= d;
		}
	}
}
int ans[N];
int main()
{
	while(cin >> n)
	{
		un = vn = n;
		for(int i = 1;i<=n;i++)
			cin >> p[i].x >> p[i].y;
		for(int i = 1;i<=n;i++)
			cin >> q[i].x >> q[i].y;
		memset(Map,0,sizeof(Map));
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				Map[i][j] = -dis(p[i],q[j]);
		km();
		for(int i = 1;i<=n;i++)
			ans[pre[i]] = i;	
		for(int i = 1;i<=n;i++)
			cout << ans[i] << endl;
	}
	return 0;
}
