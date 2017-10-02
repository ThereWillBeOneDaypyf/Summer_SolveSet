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

long long f[N];
long long judge(int n)
{
	int temp = n;
	if (temp % 7 == 0)
		return 0;
	while (temp)
	{
		if (temp % 10 == 7)
			return 0;
		temp /= 10;
	}
	return 1LL * n * n;
}
void solve()
{
	memset(f, 0, sizeof(f));
	for (int i = 1; i < N; i++)
	{
		f[i] = f[i - 1] + judge(i);
	}
}
int main()
{
	int T;
	cin >> T;
	solve();
	while (T--)
	{
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
}