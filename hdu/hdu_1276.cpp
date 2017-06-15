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
int v[N];
int cnt[N];
int dp[N];
void compelte_bag(int pos, int m)
{
	for (int i = v[pos]; i <= m; i++)
		if (dp[i - v[pos]] != -1)
			dp[i] = max(dp[i], dp[i - v[pos]] + v[pos]);
}
void zero_one_bag(int pos, int m)
{
	int base = 1;
	int ret = cnt[pos];
	while (ret >= base)
	{
		ret -= base;
		int wei = base * v[pos];
		for (int i = m; i >= wei; i--)
			if (dp[i - wei] != -1)
				dp[i] = max(dp[i], dp[i - wei] + wei) ;
		base *= 2;
	}
	int wei = ret * v[pos];
	if (wei)
		for (int i = m; i >= wei; i--)
			if (dp[i - wei] != -1)
				dp[i] = max(dp[i], dp[i - wei] + wei);
}
int main()
{
	int n, m;
	while (cin >> m >> n)
	{
		CLR(dp, 0);
		for (int i = 0; i < n; i++)
			cin >> cnt[i] >> v[i];
		for (int i = 0; i < n; i++)
		{
			if (cnt[i]*v[i] >= m)
				compelte_bag(i, m);
			else
				zero_one_bag(i, m);
		}
		cout << dp[m] << endl;
	}
}