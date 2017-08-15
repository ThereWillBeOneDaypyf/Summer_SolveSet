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
	int x, y;
	double ratio;
	long long val;
	int flag;
	void get_ratio()
	{
		ratio = 1.0 * x / y;
		if (y < 0)
			flag = 1;
		else
			flag = 0;
	}
	bool operator < (const Node &rhs) const
	{
		return ratio < rhs.ratio;
	}
} a[N];
long long sum[2];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%lld", &a[i].x, &a[i].y, &a[i].val);
			a[i].get_ratio();
			sum[a[i].flag] += a[i].val;
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			a[i + n] = a[i];
			a[i + n].flag ^= 1;
		}
		long long ans = sum[0] * sum[1];
		for (int i = 0; i < 2 * n; i++)
		{
			sum[a[i].flag] -= a[i].val;
			sum[a[i].flag ^ 1] += a[i].val;
			ans = max(ans, sum[0] * sum[1]);
			//cout << "a[i] " << a[i].val << " " << a[i].flag << "sum0 " << sum[0] << "sum1 " << sum[1] << endl;
		}
		printf("%lld\n", ans);
	}
}