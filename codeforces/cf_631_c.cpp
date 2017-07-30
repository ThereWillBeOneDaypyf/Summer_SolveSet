#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;

int a[N];
pair<int, int>Q[N];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (int i = 0; i < q; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			Q[i] = make_pair(x, y);
		}
		int cur = 0;
		for (int i = q - 1 ; i >= 0; i--)
		{
			int type = Q[i].first;
			int pos = Q[i].second;
			if (pos <= cur)
				continue;
			else
			{
				if (type == 1)
				{
					cout << cur << " " << pos << endl;
					sort(a + cur + 1, a + pos);
				}
				else
				{
					cout << cur << " " << pos << endl;
					sort(a + cur + 1, a + pos, cmp);
				}
				cur = pos;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (i != 1)
				printf(" ");
			printf("%d", a[i]);
		}
		printf("\n");
	}
}