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
	int s;
	while (cin >> s)
	{
		int ans = 1e9;
		for (int i = 1; i <= sqrt(s); i++)
			if (s % i == 0)
			{
				ans = min(ans, i + s / i);
			}
		cout << ans * 2 << endl;
	}
}