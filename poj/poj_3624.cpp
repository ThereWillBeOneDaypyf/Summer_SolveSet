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

int w[N], v[N];
int dp[N];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		CLR(dp, 0);
		for (int i = 0; i < n; i++)
			cin >> w[i] >> v[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = m; j >= w[i]; j--)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		cout << dp[m] << endl;
	}
}
