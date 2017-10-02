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
	int n;
	while (T--)
	{
		cin >> n;
		int flag = 0;
		for (int i = 0; i < 1e5; i++)
		{
			long long ans = 1LL * (1 + i) * i / 2;
			if (ans + 1 == n)
				flag = 1;
			if (ans > n)
				break;
		}
		if (flag)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
}