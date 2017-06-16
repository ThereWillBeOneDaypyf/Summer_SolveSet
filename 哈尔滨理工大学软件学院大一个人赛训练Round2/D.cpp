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

int a[N];
int vis[N];
int dp[N];
int main()
{
	int l, s, t, n;
	while (cin >> l >> s >> t >> n)
	{
		CLR(vis, 0);
		CLR(dp, INF);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			vis[a[i]] = 1;
		}
		dp[0] = 0;
		vis[0] = 1;
		for (int i = 0 ; i < l ; i ++)
		{
			for (int j = i + s ; j <= i + t; j++)
			{
				if (j >= l)
					dp[l] = min(dp[l], dp[i]);
				else if (vis[j])
					dp[j] = min(dp[i] + 1, dp[j]);
				else dp[j] = min(dp[j], dp[i]);
			}
		}
		// for (int i = 0; i <= l; i++)
		// 	cout << dp[i] << " ";
		// cout << endl;
		cout << dp[l]  << endl;
	}
}