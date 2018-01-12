#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

int sz[N];
int deg[N];
vector<int> G[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
	memset(sz, 0, sizeof(sz));
	memset(deg, 0, sizeof(deg));
}
void add_edge(int u, int v)
{
	G[u].push_back(v);
}
int main()
{
	int n;
	while (cin >> n)
	{
		init();
		for (int i = 2; i <= n; i++)
		{
			int f;
			cin >> f;
			add_edge(f, i);
			deg[f] ++;
		}
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!deg[i])
				continue;
			int cnt = 0;
			for (auto v : G[i])
				if (!deg[v])
					cnt ++;
			if (cnt < 3)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}