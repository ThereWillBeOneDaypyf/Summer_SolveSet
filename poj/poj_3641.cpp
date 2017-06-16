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

ll MOD ;

ll pow_mod(ll a, ll p)
{
	if (p == 0)
		return 1;
	ll ans = ((pow_mod(a, p / 2) % MOD) * (pow_mod(a, p / 2) % MOD)) % MOD ;
	if (p % 2 == 1)
		ans = ans * a % MOD;
	return ans;
}
bool judge(ll x)
{
	if (x == 1)
		return false;
	if (x == 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return true;
	return false;
}

int main()
{
	ll a, p;
	while (cin >> p >> a)
	{
		if (p == 0 && a == 0)
			break;
		MOD = p;
		ll ans = pow_mod(a, p);
		int flag = judge(p);
		if ((ans % MOD == a % MOD) && flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}