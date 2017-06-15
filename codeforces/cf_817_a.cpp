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
	int x1, y1, x2, y2;
	int a, b;
	while (cin >> x1 >> y1 >> x2 >> y2 >> a >> b)
	{
		if (((x1 - x2)) % a == 0 && ((y1 - y2) % b) == 0)
		{
			int k1 = (x1 - x2) / a;
			int k2 = (y1 - y2) / b;
			if ((k1 - k2) % 2 == 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
	}
}