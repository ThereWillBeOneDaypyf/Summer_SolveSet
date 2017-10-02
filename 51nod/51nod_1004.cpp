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

long long pow_mod(int a, int n)
{
	if (n == 0)
		return 1;
	long long temp = pow_mod(a, n / 2);
	temp  = temp * temp % MOD;
	if (n % 2)
		temp = temp * a % MOD;
	return temp;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << pow_mod(n, n) % MOD << endl;
	}
}