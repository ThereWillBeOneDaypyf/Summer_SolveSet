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
const ll Max_R = 2 * 1e9 + 5;
ll city[N];
ll Pow[N];
int n, m;
bool judge(ll l)
{
	int cur_power = 0;
	for (int i = 0; i < n; i++)
	{
		if (city[i] <= Pow[cur_power] + l && city[i] >= Pow[cur_power] - l)
			continue;
		while (cur_power < m && city[i] > Pow[cur_power] + l)
			cur_power ++;
		if (cur_power == m || Pow[cur_power] - l > city[i])
			return false;
	}
	return true;
}
int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			cin >> city[i];
		for (int i = 0; i < m; i++)
			cin >> Pow[i];
		sort(city, city + n);
		sort(Pow, Pow + m);
		ll l = 0, r = Max_R, mid;
		ll ans = Max_R;
		while (l <= r)
		{
			mid = (l + r) / 2;
			if (judge(mid))
			{
				ans = min(mid, ans);
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		cout << ans << endl;
	}
}