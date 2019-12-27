#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

struct Edge
{
	int v, w, id;
};

int n;
long long sum = 0;
int a[N];
int w[N];
long long dp[N];
long long cnt[N];
int vis[N];
long long ans[N];
vector<Edge> G[N];

void init()
{
	long long sum = 0;
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(dp, 0, sizeof(dp));
	for(int i = 0;i  < N; i ++)
		G[i].clear();
}

void addEdge(int u, int v, int w, int id)
{
	G[u].push_back({v, w, id});
	G[v].push_back({u, w, id});
}

void dfs(int u)
{	
	if(vis[u])
		return;
	vis[u] = 1;
	for(auto edge : G[u])
	{
		int v = edge.v;
		int w = edge.w;
		int id = edge.id;
		if(vis[v])
			continue;
		dfs(v);
		dp[u] += dp[v];
		cnt[u] += cnt[v];
		long long top = sum - dp[v];
		long long top_cnt = n - cnt[v];
		cout << u << " " <<  v << " top: " << top  << " top_cnt: " << top_cnt << endl;
		ans[id] = 2LL * (1LL * top * cnt[v] * w + 1LL * top_cnt * dp[v] * w);
	}
	cnt[u] += 1;
	dp[u] += a[u];
}

int main()
{
	while(cin >> n)
	{
		init();
		for(int i = 1; i <= n; i++)
			cin >> a[i], sum += a[i];
		for(int i = 1; i <= n - 1; i ++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			addEdge(u, v, w, i);
		}
		dfs(1);
		cout << ans[1];
		for(int i = 2;i <= n - 1; i ++)
			cout << " " << ans[i];
		cout << endl;
	}
}
