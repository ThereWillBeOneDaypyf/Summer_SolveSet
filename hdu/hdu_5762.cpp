#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

struct Node
{
	int x, y;
};

vector<Node>v;
int vis[200005];
int main()
{
	int n, m;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		memset(vis, 0, sizeof(vis));
		v.clear();
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back({x, y});
		}
		int flag = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int dis = abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y);
				if (!vis[dis])
					vis[dis] = 1;
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
}