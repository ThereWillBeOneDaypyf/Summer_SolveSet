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
using namespace std;

//thanks to pyf ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e5 + 5;

ll a[N];
ll pre_sum[N];
bool judge(ll n, ll m, ll w, ll tar)
{
	CLR(pre_sum, 0);
	for (int i = 0; i < n; i++)
	{
		i != 0 ? pre_sum[i] = pre_sum[i - 1] : pre_sum[i] = 0;
		ll cur = pre_sum[i];
		if (i >= w)
			cur -= pre_sum[i - w];
		if (cur + a[i] < tar)
		{
			pre_sum[i] += (tar - cur - a[i]);
		}
	}
	return pre_sum[n - 1] <= m;
}

int main()
{
	ll n, m, w;
	while (cin >> n >> m >> w)
	{
		ll l = INF, r = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			l = min(a[i], l);
			r = max(a[i], r);
		}
		r += m;
		//	r = INF;
		//	cout << l << " " << r << endl;
		ll ans ;
		ll mid ;
		while (l <= r)
		{
			mid = (l + r) / 2;
//			cout << mid << endl;
			if (judge(n, m, w, mid))
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		cout << ans << endl;
	}
	return 0;
}