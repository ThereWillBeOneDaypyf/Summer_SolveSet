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
	int h;
	int id;
	bool operator < (const Query &rhs) const
	{
		return h < rhs.h;
	}
} Q[N];
struct Island
{
	int h;
	int id;
	bool operator < (const Island &rhs) const
	{
		return h < rhs.h;
	}
} a[N];
int ans[N];
int vis[N];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].h;
			a[i].id = i;
		}
		for (int i = 1 ; i <= m; i++)
		{
			cin >> Q[i].h;
			Q[i].id = i;
		}
		sort(a + 1, a + 1 + n);
		sort(Q + 1, Q + 1 + m);
		int sum = 1;
		int cur_Island_pos = 1;
		CLR(vis, 0);
		for (int i = 1; i <= m; i++)
		{
			while (a[cur_Island_pos].h <= Q[i].h && cur_Island_pos <= n)
			{
				if (a[cur_Island_pos].id == 1)
				{
					if (vis[2])
						sum --;
				}
				else if (a[cur_Island_pos].id == n)
				{
					if (vis[n - 1])
						sum--;
				}
				else
				{
					if (vis[a[cur_Island_pos].id - 1] && vis[a[cur_Island_pos].id + 1])
						sum --;
					else if (!vis[a[cur_Island_pos].id - 1] && !vis[a[cur_Island_pos].id + 1])
						sum ++;
				}
				vis[a[cur_Island_pos].id] = 1;
				cur_Island_pos ++;
			}
			ans[Q[i].id] = sum;
		}
		for (int i = 1 ; i <= m; i++)
			cout << ans[i] << endl;
	}
}