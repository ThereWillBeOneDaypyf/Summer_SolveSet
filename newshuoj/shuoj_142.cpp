#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

int rt[N];
int val[N];

void init()
{
	for (int i = 0; i < N; i++)
		rt[i] = i, val[i] = 0;
}
int find(int x)
{
	if (rt[x] == x)
		return x;
	int temp = find(rt[x]);
	val[x] += val[rt[x]];
	return rt[x] = temp;
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		init();
		int flag = 1;
		for (int i = 0; i < m; i++)
		{
			int l, r, v;
			cin >> l >> r >> v;
			l--;
			int rt1 = find(l);
			int rt2 = find(r);
			if (rt1 != rt2)
			{
				rt[rt2] = rt1;
				val[rt2] = v - (val[r] - val[l]);
			}
			else if (val[r] - val[l] != v)
				flag = 0;
		}
		if (flag)
			cout << "Unknown!" << endl;
		else
			cout << "Error!" << endl;
	}
	return 0;
}