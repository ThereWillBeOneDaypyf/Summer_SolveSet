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

int n, m;
struct Node
{
	int hp, a;
	bool operator < (const Node &rhs) const
	{
		//return a * ((hp + m - 1) / m) > rhs.a * ((rhs.hp + m - 1) / m);
		return a * ((rhs.hp + m - 1) / m) > rhs.a * ((hp + m - 1) / m);
	}
} a[N];

int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		long long sum = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].hp >> a[i].a;
			sum += a[i].a;
		}
		sort(a, a + n);
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			ans += sum * ((a[i].hp + m - 1) / m);
			sum -= a[i].a;
		}
		cout << "Case #" << ++ ka << ": " ;
		cout << ans << endl;
	}
}