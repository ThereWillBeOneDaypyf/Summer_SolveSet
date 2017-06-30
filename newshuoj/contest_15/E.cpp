#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int N = 1e4;

int fa[N * 2];

void init()
{
	for (int i = 0 ; i < N * 2 ; i++)
		fa[i] = i;
}
int find(int x)
{
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		fa[a] = b;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		init();
		cin >> n >> m;
		int flag = 1;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			if (find(x) == find(y) || find(x + n) == find(y + n))
				flag = 0;
			else
				merge(x, y + n) , merge(y, x + n);
		}
		if (!flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}