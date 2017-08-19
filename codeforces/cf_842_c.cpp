#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5 + 7;

struct Node
{
	int val, id;
	bool operator < (const Node & rhs) const
	{
		return val > rhs.val;
	}
} a[N], b[N];
bool cmp(Node x, Node y)
{
	return x.id < y.id;
}
bool cmp_b(Node x, Node y)
{
	return x.val < y.val || (x.val == y.val && x.id > y.id);
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			cin >> a[i].val;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			b[i] = {x, i};
		}
		sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n, cmp_b);
		for (int i = 1; i <= n; i++)
			a[i].id = b[i].id;
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++)
		{
			if (i != 1)
				cout << " ";
			cout << a[i].val;
		}
		cout << endl;
	}
}