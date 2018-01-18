#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 8;

int fa[N];

void init()
{
	for (int i = 0; i < N; i++)
		fa[i] = i;
}
int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (fa[a] != fa[b])
		fa[a] = fa[b];
}
int main()
{
	ios :: sync_with_stdio(false);
	int n, q;
	int ka = 0;
	while (cin >> n >> q)
	{
		init();
		cout  << "Case " << ++ ka << endl;
		for (int i = 0; i < n; i++)
		{
			decltype(find(1)) a, b;
			cin >> a >> b;
			merge(a, b);
		}
		for (int i = 0 ; i < q; i++)
		{
			int a, b;
			cin >> a >> b;
			if (find(a) == find(b))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}