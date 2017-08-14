#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...
#define INF 1e18
const int N = 3e5 + 8;

int dep[N], fa[N][22], L[N], R[N], dfn[N];
long long dis[N];
vector<pair<int, long long> > G[N];
int Index = 0;
void init()
{
	Index = 0;
	memset(dep, 0, sizeof(dep));
	for (int i = 0; i < N; i++)
		G[i].clear();
}

void add_edge(int u, int v, int d)
{
	G[u].push_back(make_pair(v, d));
	G[v].push_back(make_pair(u, d));
}
void dfs(int u, int Fa, int d, long long w)
{
	dep[u] = d;
	dis[u] = w, dfn[u] = L[u] = ++ Index;
	fa[u][0] = Fa;
	for (int i = 1; i < 21; i++)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = 0; i < G[u].size(); i++)
	{
		pair<int, long long> temp = G[u][i];
		int v = temp.first;
		long long ww = temp.second;
		if (v == Fa)
			continue;
		dfs(v, u, d + 1, min(w, ww));
	}
	R[u] = Index;
}
int lca(int u, int v)
{
	if (dep[u] < dep[v])
		swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v)
		return u;
	for (int i = 20; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
// virtual tree
vector<pair<int, long long> >VG[N];
int kp[N];
int is_k[N], st[N];
long long dp[N];
bool cmp(int u, int v) {return dfn[u] < dfn[v]; }
bool judge(int u, int v) { return L[u] <= L[v] && R[v] <= R[u];}
void add_vedge(int u, int v)
{
	VG[u].push_back(make_pair(v, 0));
	VG[v].push_back(make_pair(u, 0));
}
void tree_up(int u, int Fa)
{
	long long sum = 0;
	//cout << "*" << u << endl;
	for (int i = 0; i < VG[u].size(); i++)
	{
		pair<int, long long> temp = VG[u][i];
		if (temp.first == Fa)
			continue;
		tree_up(temp.first, u);
		sum += 1LL * dp[temp.first];
	}
	if (!sum)
		dp[u] = dis[u];
	else
		dp[u] = min(dis[u], sum);
	VG[u].clear();
}
// void build_vtree()
// {
// 	int k;
// 	scanf("%d", &k);
// 	for (int i = 0; i < k; i++)
// 	{
// 		scanf("%d", kp + i);
// 	}
// 	int cnt = k;
// 	sort(kp, kp + cnt, cmp);
// 	// for (int i = 0; i < k; i++)
// 	// 	kp[cnt++] = lca(kp[i], kp[i - 1]);
// 	kp[cnt++] = kp[0];
// 	for (int i = 1; i < k; ++i) if (lca(kp[cnt], kp[i]) != kp[cnt]) kp[cnt++] = kp[i];
// //	cnt = unique(kp, kp + cnt) - kp;
// 	int top = 0;
// 	st[++top] = 1;
// 	for (int i = 0; i < cnt; i++)
// 	{
// 		int anc = lca(st[top], kp[i]);
// 		while (1)
// 		{
// 			if (dep[anc] >= dep[st[top - 1]])
// 			{
// 				add_vedge(anc, st[top--], 0);
// 				break;
// 			}
// 			add_vedge(st[top - 1], st[top], 0);
// 			top --;
// 		}
// 		if (st[top] != anc) st[++top] = anc;
// 		if (st[top] != kp[i]) st[++top] = kp[i];
// 	}
// 	while (--top) add_vedge(st[top], st[top + 1], 0);
// 	tree_up(1, 1);
// 	printf("%lld\n", dp[1]);
// 	VG[1].clear();
// 	dp[1] = 0;
// }
int h[N];
void build_vtree()
{
	int cnt = 0;
	int K;
	int top = 0;
	scanf("%d", &K);
	for (int i = 1; i <= K; i++)
		scanf("%d", h + i);
	sort(h + 1, h + K + 1, cmp);
	int tot = 0;
	h[++tot] = h[1];
	for (int i = 2; i <= K; i++)
		if (lca(h[tot], h[i]) != h[tot])h[++tot] = h[i];
	st[++top] = 1;
	for (int i = 1; i <= tot; i++)
	{
		int now = h[i], f = lca(now, st[top]);
		while (1)
		{
			if (dep[f] >= dep[st[top - 1]])
			{
				add_vedge(f, st[top--]);
				if (st[top] != f)st[++top] = f;
				break;
			}
			add_vedge(st[top - 1], st[top]); top--;
		}
		if (st[top] != now)st[++top] = now;
	}
	while (--top)add_vedge(st[top], st[top + 1]);
	tree_up(1, 1);
	printf("%lld\n", dp[1]);
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 1; i < n; i++)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			add_edge(u, v, d);
		}
		dfs(1, 1, 0, INF);
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			build_vtree();
	}
}