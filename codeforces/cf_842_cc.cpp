#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5 + 7;
vector<int>G[N];
int dp[N][2], a[N];
set<int>s[N];
void init()
{
	for (int i = 0; i < N; i++)
		G[i].clear();
	for (int i = 0; i < N; i++)
		s[i].clear();
}
void add_edge(int u, int v)
{
	G[u].push_back(v), G[v].push_back(u);
}
void dfs(int u, int fa, int Max_unchage)
{
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		//dp[v][0] unchange dp[v][1] change
		dp[v][0] = __gcd(a[v], Max_unchage);
		dp[v][1] = Max_unchage;
		s[v].insert(Max_unchage);
		for (auto temp : s[u])
		{
			dp[v][1] = max(dp[v][1], __gcd(temp, a[v]));
			s[v].insert(__gcd(temp, a[v]));
		}
		dfs(v, u, dp[v][0]);
	}
}
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		init();
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			add_edge(x, y);
		}
		s[1].insert(0);
		dfs(1, 1, a[1]);
		cout << a[1];
		for (int i = 2; i <= n; i++)
		{
			cout << " ";
			cout << max(dp[i][0], dp[i][1]);
		}
		cout << endl;
	}
}