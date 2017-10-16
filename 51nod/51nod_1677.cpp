#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;

vector<int> G[N];
ll sz[N];
ll fac[N], inv[N];
int n, m;
ll ans = 0;
ll pow_mod(ll a, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1) res = res * a % MOD;
		a = a * a % MOD;
		n >>= 1;
	}
	return res;
}

void init(int n)
{
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = pow_mod(fac[i], MOD - 2);
		//printf("%d : %I64d %I64d\n", i, fac[i], inv[i]);
	}
}

ll C(int x, int y)
{
	if (y > x) return 0;
	if (x == y) return 1;
	return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}
void dfs(int u, int fa)
{
	sz[u] = 1;
	for (auto v : G[u])
	{
		if (v == fa)
			continue;
		dfs(v, u);
		ans = ans + (C(n, m) - C(sz[v], m) + MOD) % MOD;
		ans = ans + (MOD - C(n - sz[v], m)) % MOD;
		//cout << C(n, m) << " " << C(sz[v], m) << " " << C(n - sz[u], m) << endl;
		ans %= MOD;
		sz[u] += sz[v];
	}
}

int main()
{
	ios :: sync_with_stdio(false);
	while (cin >> n >> m)
	{
		init(n);
		for (int i = 0; i < N; i++)
			G[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		ans = 0;
		dfs(1, 1);
		cout << ans << endl;
	}
}