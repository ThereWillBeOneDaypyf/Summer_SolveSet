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

int main()
{
	int n;
	while (cin >> n)
	{
		map<int, int>m;
		map<int, int>choose;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			m[a[i]] ++;
		}
		sort(a, a + n);
		ll ans = 1;
		int cnt = 0;
		for (int i = 0; i < 3; i++)
		{
			if (!choose.count(a[i]))
				choose[a[i]] = 0;
			else
				cnt ++;
			ans *= (m[a[i]] - choose[a[i]]);
			choose[a[i]] ++;
		}
		for (int i = cnt + 1; i >= 1; i--)
			ans /= i;
		cout << ans << endl;
	}
}