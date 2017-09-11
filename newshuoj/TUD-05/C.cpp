#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

int dis[N];
int vis[N];
int n;
vector<pair<int, int> > G[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
}
void add_edge(int u, int v, int d)
{
	G[u].push_back(make_pair(v, d));
}
void spfa()
{
	queue<int>q;
	for (int i = 0; i < n; i++)
		q.push(i), vis[i] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (auto temp : G[u])
		{
			int v = temp.first;
			int d = temp.second;
			if (dis[u] + d < dis[v])
			{
				dis[v] = dis[u] + d;
				if (!vis[v])
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}
int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		int m;
		cin >> n >> m;
		init();
		for (int i = 0; i < n; i++)
			cin >> dis[i];
		for (int i = 0; i < m; i++)
		{
			int u, v, d1, d2;
			cin >> u >> v >> d1 >> d2;
			add_edge(u, v, d1);
			add_edge(v, u, d2);
		}
		spfa();
		int id = 0;
		for (int i = 0; i < n; i++)
			if (dis[id] < dis[i])
				id = i;
		cout << "Scenario #" << ++ ka << ":" << endl <<  id << endl;
		cout << endl;
	}
}