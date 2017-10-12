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

const int N = 1e6 + 1005;

int vis[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			vis[x] ++;
		}
		for (int i = 1; i <= 1e6 + 20; i++)
		{
			vis[i] += vis[i - 1] / 2;
			vis[i - 1] %= 2;
		}
		int ans = 0;
		for (int i = 0; i <= 1e6 + 100; i++)
			ans += vis[i] % 2;
		cout << ans << endl;
	}
}