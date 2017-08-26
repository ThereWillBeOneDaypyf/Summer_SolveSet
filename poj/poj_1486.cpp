#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e3;
int Map[N][N];
int vis[N];
int pre[N];
int n;
bool dfs(int u)
{
	for (int v = 1; v <= n; v++)
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
	int ans = 0;
	memset(pre, -1, sizeof(pre));
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if (dfs(i))
			ans ++;
	}
	return ans;
}
int solve()
{
	int cur = hungry();
	int cnt = 0;
	if (cur == n)
	{
		vector<pair<char, int> > ans;
		ans.clear();
		for (int i = 1; i <= n; i++)
		{
			char x = 'A' + i - 1;
			ans.push_back(make_pair(x, pre[i])); // first letter second number
		}
		for (int i = 0; i < n; i++)
		{
			int u = ans[i].first - 'A' + 1, v = ans[i].second;
			Map[v][u] = 0;
			if (hungry() == n)
				continue;
			else
			{
				if (cnt)
					printf(" ");
				printf("(%c,%d)", ans[i].first, ans[i].second);
				cnt ++;
			}
			Map[v][u] = 1;
		}
		if (cnt)
			cout << endl;
		return cnt;
	}
	else return 0;
}
struct Node
{
	int x[2], y[2];
} a[N];
int main()
{
	int ka = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		memset(Map, 0, sizeof(Map));
		for (int i = 1; i <= n; i++) // 字母
			cin >> a[i].x[0] >> a[i].x[1] >> a[i].y[0] >> a[i].y[1];
		for (int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y;
			for (int j = 1; j <= n; j++) // letter
			{
				if (a[j].x[0] <= x && x <= a[j].x[1] && a[j].y[0] <= y && y <= a[j].y[1])
					Map[i][j] = 1;
			}
		}
		cout << "Heap " << ++ka << endl;
		if (!solve())
			cout << "none" << endl;
		cout << endl;
	}
	return 0;
}