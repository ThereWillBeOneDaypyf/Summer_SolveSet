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
	ll n, s;
	while (cin >> n >> s)
	{
		ll x = (s + 8) / 9;
		ll cnt =  1;
		ll r = n;
		while (cnt <= x)
		{
			cnt *= 10;
			cnt += 1;
		}
		cnt /= 10;
		ll least = 0;
		while (cnt)
		{
			least *= 10;
			least += x / cnt;
			x -= x / cnt * cnt;
			cnt /= 10;
		}
		if (x)
			least += 1;
		least *= 10;
		cout << max((ll) 0 , n - least + 1) << endl;
	}
}
