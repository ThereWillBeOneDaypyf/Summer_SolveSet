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

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;


struct Seg
{
	ll l, r;
} s[N], final_s[N];

bool cmp(Seg a, Seg b)
{
	return a.l < b.l || (a.l == b.l && a.r < b.r);
}

int main()
{
	int n;
	ll R;
	while (scanf("%d%lld", &n, &R) == 2)
	{
		vector< pair<ll, ll> > ans;
		CLR(s, 0);
		CLR(final_s, 0);
		ans.clear();
		for (int i = 0; i < n; i++)
			scanf("%lld%lld", &s[i].l, &s[i].r);
		sort(s, s + n, cmp);
		int cnt = 0;
		final_s[cnt].l = s[0].l;
		final_s[cnt].r = s[0].r;
		for (int i = 1; i < n; i++)
		{
			if (final_s[cnt].r + 1 < s[i].l)
			{
				cnt ++;
				final_s[cnt].l = s[i].l;
				final_s[cnt].r = s[i].r;
			}
			else
			{
				final_s[cnt].l = min(final_s[cnt].l, s[i].l);
				final_s[cnt].r = max(final_s[cnt].r, s[i].r);
			}
		}
		sort(final_s, final_s + 1 + cnt, cmp);
		if (final_s[0].l > 1)
			ans.push_back(mp(1, final_s[0].l - 1));
		if (final_s[cnt].r < R)
			ans.push_back(mp(final_s[cnt].r + 1, R));
		for (int i = 0; i < cnt; i++)
		{
			ans.push_back(mp(final_s[i].r + 1, final_s[i + 1].l - 1));
		}
		if (ans.size() == 0)
			printf("Crazy ACM!\n");
		else
		{
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				printf("[%lld, %lld]\n", ans[i].first, ans[i].second);
		}
	}
}
