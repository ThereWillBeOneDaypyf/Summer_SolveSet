#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e3 + 5;

int Map[N][N];
int cx[N], cy[N];
int visx[N], visy[N];
int pre[N];
int un, vn;
bool dfs(int u)
{
	visx[u] = 1;
	for (int v =  1; v <= vn; v++)
	{
		if (!visy[v] && Map[u][v] == cx[u] + cy[v])
		{
			visy[v] = 1;
			if (pre[v] == -1 || dfs(pre[v]))
			{
				pre[v] = u;
				return true;
			}
		}
	}
	return false;
}
int km()
{
	memset(cx, 0, sizeof(cx));
	memset(cy, 0, sizeof(cy));
	memset(pre, -1, sizeof(pre));
	for (int i = 1; i <= un; i++)
		for (int j = 1; j <= vn; j++)
			cx[i] = max(cx[i], Map[i][j]);
	for (int i = 1; i <= un; i++)
	{
		while (1)
		{
			int d = INF;
			memset(visx, 0, sizeof(visx));
			memset(visy, 0, sizeof(visy));
			if (dfs(i))
				break;
			for (int i = 1; i <= un; i++)
			{
				if (visx[i])
				{
					for (int j = 1; j <= vn; j++)
					{
						if (!visy[j])
						{
							d = min(d , cx[i] + cy[j] - Map[i][j]);
						}
					}
				}
			}
			if (d == INF)
				break;
			for (int i = 1; i <= un; i++)
				if (visx[i])
					cx[i] -= d;
			for (int i = 1; i <= vn; i++)
				if (visy[i])
					cy[i] -= d;
		}
	}
	int ans = 0;
	for (int i = 1; i <= vn; i++)
		if (pre[i] != -1)
			ans += Map[pre[i]][i];
	return ans;
}
int main()
{
	int n;
	while (cin >> n)
	{
		un = vn = n;
		memset(Map, 0, sizeof(Map));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> Map[i][j];
		cout << km() << endl;
	}
}