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
const int MOD = 10;

long long pow_mod(long long a, long long x)
{
	if (x == 0)
		return 1;
	long long res = pow_mod(a, x / 2);
	res = res * res % MOD;
	if (x % 2)
		res = res * a % MOD;
	return res;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		cout << pow_mod(n, n) << endl;
	}
}