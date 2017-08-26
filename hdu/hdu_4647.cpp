#include<bits/stdc++.h>
using namespace std;

//thansk to pyf ...
//thanks to qhl ...
const int N = 1e5 + 7;
struct Edge
{
	int u, v, d;
};
vector<Edge>edge;
long long val[N];
bool cmp(int u, int v)
{
	return val[u] > val[v];
}
int pos[N];
int clr[N];
int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		memset(clr, 0, sizeof(clr));
		for (int i = 1; i <= n; i++)
		{
			cin >> val[i];
			val[i] *= 2;
			pos[i] = i;
		}
		for (int i = 1; i <= m; i++)
		{
			int u, v, d;
			cin >> u >> v >> d;
			edge.push_back({u, v, d});
			val[u] += d, val[v] += d;
		}
		sort(pos + 1, pos + 1 + n, cmp);
		int flag = 1;
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			clr[pos[i]] = flag;
			ans += (long long)flag * val[pos[i]];
			flag *= -1;
		}
		// for (auto temp : edge)
		// {
		// 	int u = temp.u , v = temp.v , d = temp.d;
		// 	if (clr[u] == clr[v])
		// 		ans -= (long long)clr[u] * d;
		// }
		cout << ans / 2 << endl;
	}
}