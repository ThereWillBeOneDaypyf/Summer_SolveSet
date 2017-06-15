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
	int n, k;
	double l, v1, v2;
	while (cin >> n >> l >> v1 >> v2 >> k)
	{
		int cnt = n / k;
		if (n % k != 0)
			cnt ++;
		double x = l * (v1 + v2) / ((cnt - 1) * 2 * v1 + v1 + v2);
		printf("%.10lf\n", (l - x) / v1 + x / v2);
	}
}