#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
const int N = 1e5 + 7;
int L, P;
struct Node
{
	int dis, v;
	void update()
	{
		dis = L - dis;
	}
	bool operator < (const Node & rhs) const
	{
		return dis < rhs.dis;
	}
} a[N];
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].dis, &a[i].v);
		scanf("%d%d", &L, &P);
		for (int i = 0; i < n; i++)
			a[i].update();
		sort(a, a + n);
		int flag = 1;
		int cur = 0;
		int id = 0;
		priority_queue<int>q;
		while (id < n && a[id].dis <= cur)
			q.push(a[id++].v);
		int ans = 0;
		while (cur < L)
		{
			if (P == 0)
			{
				if (q.empty())
				{
					flag = 0;
					break;
				}
				else
				{
					P = q.top();
					q.pop();
					ans ++;
				}
			}
			cur ++;
			P--;
			while (id < n && a[id].dis <= cur)
				q.push(a[id++].v);
		}
		if (!flag)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
}