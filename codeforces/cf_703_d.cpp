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

struct Query
{
	int l, r, id;
	int ans;
} Q[N];
int BIT[N];
int ox_sum[N];
int a[N];
int n;
bool cmp(Query a, Query b)
{
	return a.r < b.r;
}
bool cmp_id(Query a, Query b)
{
	return a.id < b.id;
}
int lowbit(int x)
{
	return x & (-x);
}
void update(int pos, int val)
{
	while (pos <= n)
	{
		BIT[pos] ^= val;
		pos += lowbit(pos);
	}
}
int query(int pos)
{
	int ans = 0;
	while (pos > 0)
	{
		ans ^= BIT[pos];
		pos -= lowbit(pos);
	}
	return ans;
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		CLR(ox_sum, 0);
		CLR(BIT, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			ox_sum[i] = ox_sum[i - 1] ^ a[i];
		}
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			scanf("%d%d", &Q[i].l , &Q[i].r);
			Q[i].id = i;
		}
		sort(Q, Q + q, cmp);
		int cur_update = 1;
		map<int, int>most_right;
		for (int i = 0; i < q; i++)
		{
			for (; cur_update <= Q[i].r; cur_update++)
			{
				if (most_right.count(a[cur_update]))
				{
					update(most_right[a[cur_update]], a[cur_update]);
				}
				most_right[a[cur_update]] = cur_update;
				update(cur_update, a[cur_update]);
			}
			// cout << query(Q[i].r) << " " << query(Q[i].l - 1) << " " << ox_sum[Q[i].r] << " " << ox_sum[Q[i].l - 1] << endl;
			Q[i].ans = query(Q[i].r) ^ query(Q[i].l - 1) ^ ox_sum[Q[i].r] ^ ox_sum[Q[i].l - 1];
			map<int, int> :: iterator it;
			// for (it = most_right.begin(); it != most_right.end(); it++)
			// {
			// 	int value = it -> first;
			// 	int right = it -> second;
			// 	if (right < Q[i].l)
			// 	{
			// 		Q[i].ans ^= value;
			// 	}
			// }
		}
		sort(Q, Q + q, cmp_id);
		for (int i = 0; i < q; i++)
			printf("%d\n", Q[i].ans);
	}
}
