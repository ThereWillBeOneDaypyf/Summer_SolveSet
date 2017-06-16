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
int b[N];
int main()
{
	int n, m;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> b[i];
		ll ans = INF;
		for (int i = 0; i < m - n; i++)
		{
			ll sum = 0;
			int tempi = i;
			for (int j = 0 ; j < n; j++)
			{
				sum += (a[j] - b[tempi]) * (a[j] - b[tempi++]);
			}
			ans = min(ans, sum);
		}
		cout << ans << endl;
	}
}