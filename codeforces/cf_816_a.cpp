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


int a[2], b[2];

bool judge()
{
	for (int i  = 0 ; i < 2; i++)
		if (a[i] != b[1 - i])
			return false;
	return true;
}
void Plus()
{
	int x = a[1] * 10 + a[0];
	int y = b[1] * 10 + b[0];
	y ++;
	if (y >= 60)
		y = 0 , x ++;
	if (x >= 24)
		x = 0;
	a[1] = x / 10;
	a[0] = x % 10;
	b[1] = y / 10;
	b[0] = y % 10;
}

int main()
{
	int x, y;
	while (scanf("%d:%d", &x, &y) == 2)
	{
		a[1] = x / 10;
		a[0] = x % 10;
		b[1] = y / 10;
		b[0] = y % 10;
		int ans = 0;
		while (!judge())
		{
			Plus(), ans++;
		}

		cout << ans << endl;

	}
}