#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1000;

struct STUDEND
{
	int h;
	string sex, music, sport;
} a[N];
int Map[N][N];
int n;
int vis[N], pre[N];

bool dfs(int u)
{
	for (int v = 0; v < n; v++)
	{
		if (Map[u][v] && !vis[v])
		{
			vis[v] = 1;
			if (pre[v] == -1 || dfs(pre[v]))
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
	memset(pre, -1, sizeof(pre));
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (dfs(i))
			ans ++;
	}
	return ans;
}
bool judge(int i, int j)
{
	if (abs(a[i].h - a[j].h) > 40 || a[i].sex == a[j].sex || a[i].music != a[j].music || a[i].sport == a[j].sport)
		return true;
	return false;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		memset(Map, 0, sizeof(Map));
		for (int i = 0; i < n; i++)
			cin >> a[i].h >> a[i].sex >> a[i].music >> a[i].sport;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!judge(i, j))
					Map[i][j] = 1;
			}
		}
		cout << n - hungry() / 2 << endl;
	}
}