#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;

int v[N];
struct Node
{
	int l, r;
} a[N];
int get_id(int val, int len)
{
	return lower_bound(v, v + len, val) - v + 1;
}
int sum[N];
bool judge()
{
	for (int i = 0; i < N; i++)
		if (sum[i] > 2)
			return false;
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int tot = 0;
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].l >> a[i].r;
			v[tot++] = a[i].l, v[tot++] = a[i].r;
		}
		sort(v, v + tot);
		tot = unique(v, v + tot) - v;
		for (int i = 0; i < n; i++)
		{
			sum[get_id(a[i].l, tot)] ++;
			sum[get_id(a[i].r, tot) + 1] --;
		}
		for (int i = 1; i < N; i++)
			sum[i] = sum[i - 1] + sum[i];
		if (judge())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

