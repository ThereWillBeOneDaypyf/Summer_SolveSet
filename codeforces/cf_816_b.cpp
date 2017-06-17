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

struct Node
{
	int l, r;
} a[N];

int pre_sum[N];
int cnt[N];
int ans_pre_sum[N];

int main()
{
	int n, k, q;
	const int limit = 200000;
	while (cin >> n >> k >> q)
	{
		CLR(pre_sum, 0);
		CLR(cnt, 0);
		CLR(ans_pre_sum, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].l  >> a[i].r;
			cnt[a[i].l] ++;
			cnt[a[i].r + 1] --;
		}
		for (int i = 1; i <= limit; i++)
			pre_sum[i] = pre_sum[i - 1] + cnt[i];
		for (int i = 1; i <= limit; i++)
		{
			ans_pre_sum[i] = ans_pre_sum[i - 1] + ((pre_sum[i]) >= k);
		}
		for (int i = 0; i < q; i++)
		{
			int L, R;
			cin >> L >> R;
			cout << ans_pre_sum[R] - ans_pre_sum[L - 1] << endl;
		}
	}
}