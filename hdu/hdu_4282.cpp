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
ll k;
ll mat[50001][32];
void f()
{
	CLR(mat, 0);
	for (int i = 1; i <= 50000; i++)
	{
		mat[i][1] = i;
		for (int j = 2; j < 32; j++)
		{
			mat[i][j] = mat[i][j - 1] * i ;
			if (mat[i][j] >  2147483648LL)
				break;
		}
	}
}
bool search(ll res, ll x, ll z)
{
	ll l = x + 1, r = 50000, y;
	while (l <= r)
	{
		y = (l + r) / 2;
		if (mat[y][z] == 0)
		{
			r = y - 1;
			continue;
		}
		ll tar = mat[y][z] + x * y * z;
		if (tar == (k - res))
			return true;
		if (tar < (k - res))
			l = y + 1;
		else
			r = y - 1;
	}
	return false;
}
int main()
{
	f();
	while (cin >> k && k)
	{
		int ans = 0;
		for (ll x = 1; x <= 50000 && x <= k; x++)
		{
			for (ll z = 2; z < 32; z++)
			{
				if (mat[x][z] == 0)
					break;
				ll res = mat[x][z];
				if (res > k)
					break;
				if (search(res, x, z))
					ans ++;
			}
		}
		cout << ans << endl;
	}
}