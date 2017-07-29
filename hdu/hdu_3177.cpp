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
	int need, val;
	bool operator < (const Node &rhs) const
	{
		return val + rhs.need < rhs.val + need;
	}
} a[N];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int m, n;
		cin >> m >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i].val >> a[i].need;
		sort(a, a + n);
		int ans;
		for (ans = 0; ans < n; ans++)
		{
			if (m >= a[ans].need)
			{
				m -= a[ans].val;
			}
			else
				break;
		}
		if (ans == n)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}