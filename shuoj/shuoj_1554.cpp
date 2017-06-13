#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;


int Map[105][105];
int vis[105][105];
int xdir[4] = {0, 1, 0, -1};
int ydir[4] = {1, 0, -1, 0};
int n, m;
int flag = 0;
bool ok(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	return true;
}
void dfs(int i, int j)
{
	vis[i][j] = 1;
	if (i == n - 1 && j == m - 1)
	{
		flag = 1;
		return;
	}
	for (int k = 0; k < 4; k++)
	{
		int tx = i + xdir[k];
		int ty = j + ydir[k];
		if (!ok(tx, ty) || vis[tx][ty] || Map[tx][ty] == 1)
			continue;
		dfs(tx, ty);
	}
}
int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> Map[i][j];
			}
		}
		flag = 0;
		CLR(vis, 0);
		dfs(0, 0);
		if (flag)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}