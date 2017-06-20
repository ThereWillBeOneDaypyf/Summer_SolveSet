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

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		ll n;
		cin >> n;
		ll ans = 0;
		ll base = 2;
		while (base <= n)
		{
			ans += (n / base);
			base *= 2;
		}
		cout << ans << endl;
	}
}