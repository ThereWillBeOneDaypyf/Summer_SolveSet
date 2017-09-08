#include<bits/stdc++.h>
using namespace std;
//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Tire
{
	int next[2];
	int val;
} t[N * 32 * 2];
struct Edge
{
	int u, v, next;
} edge[N * 2];
int head[N];
int cnt = 0, tot = 0, Index = 0;
int key[N], L[N], R[N];
int root[N];
void init()
{
	memset(head, -1, sizeof(head));
	cnt = 0, tot = 0, Index = 0;
}
void init_Node(int id)
{
	t[id].next[0] = t[id].next[1] = t[id].val = 0;
}
void add_edge(int u, int v)
{
	edge[tot] = {u, v, head[u]};
	head[u] = tot ++;
}
void update(int x, int y, int k)
{
	int b[31];
	for (int i = 0; i <= 30; i++)
	{
		b[i] = k & 1;
		k >>= 1;
	}
	root[x] = ++cnt;
	init_Node(cnt);
	int rx = root[x], ry = root[y];
	for (int i = 30; i >= 0; i--)
	{
		t[rx].next[b[i]] = ++cnt;
		init_Node(t[rx].next[b[i]]);
		t[rx].next[(b[i] ^ 1)] = t[ry].next[(b[i] ^ 1)];
		t[rx].val = t[ry].val + 1;
		rx = t[rx].next[b[i]] , ry = t[ry].next[b[i]];
	}
	t[rx].val = t[ry].val + 1;
	// rx = root[x], ry = root[y];
	// for (int i = 30; i >= 0; i--)
	// {
	// 	if (t[t[rx].next[0]].val > t[t[ry].next[0]].val)
	// 	{
	// 		cout << 0;
	// 		rx = t[rx].next[0], ry = t[ry].next[0];
	// 	}
	// 	else
	// 	{
	// 		cout << 1;
	// 		rx = t[rx].next[1], ry = t[ry].next[1];
	// 	}
	// }
	// cout << endl;
}
int query(int l, int r, int val)
{
	int b[31];
	for (int i = 0; i <= 30; i++)
	{
		b[i] = val & 1;
		b[i]  ^= 1, val >>= 1;
	}
	int ans = 0;
	for (int i = 30; i >= 0; i--)
	{
		if (t[t[r].next[b[i]]].val > t[t[l].next[b[i]]].val)
		{
			ans += (b[i]) * (1 << i);
			l = t[l].next[b[i]], r = t[r].next[b[i]];
		}
		else
		{
			ans += (b[i] ^ 1) * (1 << i);
			l = t[l].next[b[i] ^ 1], r = t[r].next[b[i] ^ 1];
		}
	}
	return ans;
}
void dfs(int u)
{
	L[u] = ++ Index;
	for (int i = head[u]; ~i; i = edge[i].next)
	{
		int v = edge[i].v;
		dfs(v);
	}
	R[u] = Index;
}
int pos[N];
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		init();
		for (int i = 1; i <= n; i++)
			scanf("%d", key + i);
		for (int i = 2; i <= n; i++)
		{
			int f;
			scanf("%d", &f);
			add_edge(f, i);
		}
		dfs(1);
		for (int i = 1; i <= n; i++)
			pos[L[i]] = i;
		for (int i = 1; i <= n; i++)
			update(i, i - 1, key[pos[i]]);
		for (int i = 0; i < q; i++)
		{
			int u, x;
			scanf("%d%d", &u, &x);
			printf("%d\n", x ^ query(root[L[u] - 1], root[R[u]], x));
		}
	}
}