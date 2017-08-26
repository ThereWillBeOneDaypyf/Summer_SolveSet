#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;

int BIT[N];
int n;
int lowbit(int x) {return x & (-x);}
void update(int x)
{
	while (x <= n)
	{
		BIT[x] ++;
		x += lowbit(x);
	}
}
int query(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += BIT[x];
		x -= lowbit(x);
	}
	return res;
}
struct Node
{
	int l, r;
} a[N];
int tar[N];
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		memset(BIT, 0, sizeof(BIT));
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &tar[i]);
			a[tar[i]].l = min(i, tar[i]);
		}
		for (int i = n; i >= 1; i--)
		{
			int add = query(tar[i]);
			a[tar[i]].r = i + add;
			update(tar[i]);
		}
		printf("Case #%d:", ++ ka);
		for (int i = 1; i <= n; i++)
		{
			printf(" ");
			printf("%d", a[i].r - a[i].l);
		}
		printf("\n");
	}
}