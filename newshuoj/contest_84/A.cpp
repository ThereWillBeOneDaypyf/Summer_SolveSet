#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

vector<int> G[N];
int vis[N];
int pre[N];
int n;
void init()
{
	for(int i = 0;i < N;i++)
		G[i].clear();
}
bool dfs(int u)
{
	for(auto v : G[u])
	{
		if(vis[v])
			continue;
		vis[v] = 1;
		if(pre[v] == -1 || dfs(pre[v]))
		{
			pre[v] = u;
			return true;
		}
	}
	return false;
}
int solve()
{
	memset(pre,-1,sizeof(pre));
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i))
			ans ++;
	}
	return ans;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		init();
		vector<pair<int,int> > v;
		cin >> n;
		for(int i = 0;i < n;i++)
		{
			int x;
			cin >> x;
			v.push_back(make_pair(x,x));
		}
		for(int i = 0;i < n;i++)
		{
			int x;
			cin >> x;
			v[i].first = max(v[i].first - x,0);
			v[i].second = v[i].second + x;
		}
		int m;
		cin >> m;
		for(int i = 0;i < m;i++)
		{
			int x;
			cin >> x;
			for(int j = 0;j < n;j++)
			{
				pair<int,int> temp = v[j];
				if(temp.first <= x && x <= temp.second)
					G[j].push_back(i);
			}
		}
		cout << solve() << endl;
	}
}
