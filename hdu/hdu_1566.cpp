#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

struct Tree
{
	int l, r;
	int sum;
	int vis;
} t[N * 4];

void push_up(int step)
{
	t[step].sum = t[step * 2].sum + t[step * 2 + 1].sum;
}
void push_down(int step)
{
	if (!t[step].vis)
		return;
	t[step * 2].vis += t[step].vis;
	t[step * 2 + 1].vis += t[step].vis;
	t[step * 2].sum += t[step].vis * (t[step * 2].r - t[step * 2].l + 1);
	t[step * 2 + 1].sum += t[step].vis * (t[step * 2 + 1].r - t[step * 2 + 1].l + 1);
	t[step].vis = 0;
}
void build(int l, int r, int step)
{
	t[step].l = l, t[step].r = r;
	t[step].sum = t[step].vis = 0;
	if (l == r)
		return;
	int mid = (l + r) / 2;
	build(l, mid, step * 2);
	build(mid + 1, r, step * 2 + 1);
}
void update(int l, int r, int step)
{
	if (l == t[step].l && r == t[step].r)
	{
		t[step].sum += (t[step].r - t[step].l + 1);
		t[step].vis ++;
		return ;
	}
	push_down(step);
	int mid = (t[step].l + t[step].r) / 2;
	if (r <= mid)
		update(l, r, step * 2);
	else if (l > mid)
		update(l, r, step * 2 + 1);
	else
		update(l, mid, step * 2) , update(mid + 1, r, step * 2 + 1);
	push_up(step);
}
int query(int l , int r , int step)
{
	if (l == t[step].l && r == t[step].r)
		return t[step].sum;
	int mid = (t[step].l + t[step].r) / 2;
	push_down(step);
	if (r <= mid)
		return query(l, r, step * 2);
	else if (l > mid)
		return query(l, r, step * 2 + 1);
	else
		return query(l, r, step * 2) + query(l, r, step * 2 + 1);
}
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
			break;
		build(1, N / 10 + 2, 1);
		for (int i = 0; i < n; i++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			update(l, r, 1);
		}
		for (int i = 1; i <= n; i++)
			i == n ? printf("%d\n", query(i, i, 1)) : printf("%d ", query(i, i, 1));
	}
}