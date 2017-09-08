#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...
int n, m;
long long  a[1000000];
struct Node
{
	int l, r, t;
};
vector<Node>v;
void init()
{
	memset(a, 0, sizeof(a));
	v.clear();
}
int lowbit(int x)
{
	return x & (-x);
}
void update(int pos, int val)
{
	while (pos <= n + m)
	{
		a[pos] += val;
		pos += lowbit(pos);
	}
}
long long  query(int pos)
{
	long long ans = 0;
	while (pos > 0)
	{
		ans += a[pos];
		pos -= lowbit(pos);
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	int k = 0;
	while (T--)
	{
		scanf("%d%d", &n, &m);
		init();
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back({x, y, 0});
		}
		long long ans = 0;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back({x, y, 1});
		}
		sort(v.begin(), v.end(), [](Node a, Node b) {return a.l < b.l;});
		for (int i = 0; i < v.size(); i++)
		{
			ans += query(n + m) - query(v[i].r - 1);
			update(v[i].r, 1);
		}
		printf("Scenario #%d:\n%lld\n\n", ++k, ans);
	}
	return 0;
}