#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> G[N];
int clr[N];
int ans = 0;
void dfs(int u, int curclr)
{
	if (curclr != clr[u])
		ans ++;
	for (auto v : G[u])
		dfs(v, clr[u]);
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < N; i++)
			G[i].clear();
		for (int i = 2; i <= n; i++)
		{
			int r;
			cin >> r;
			G[r].push_back(i);
		}
		for (int i = 1; i <= n; i++)
			cin >> clr[i];
		ans = 0;
		dfs(1, -1);
		cout << ans << endl;
	}
}