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
#define PI 3.1415926535
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

struct Circle
{
	int x, y;
	int r;
	double s;
	int covered_cnt;
} c[N];

double cal_dis(Circle a, Circle b)
{
	return sqrt((double)(a.x - b.x) * (double)(a.x - b.x) + (double)(a.y - b.y) * (double)(a.y - b.y));
}

int judge(Circle x, Circle y) // -1 x 1 y
{
	if ((double)x.r + y.r <= cal_dis(x, y))
		return 0;
	else
	{
		if (x.r < y.r)
			return -1;
		else return 1;
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		CLR(c, 0);
		for (int i = 0; i < n; i++)
			cin >> c[i].x >> c[i].y >> c[i].r;
		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					if (judge(c[i], c[j]) == -1)
						c[i].covered_cnt ++ ;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			double s = 1.0 * PI * c[i].r * c[i].r;
			if (!c[i].covered_cnt)
				ans += s;
			else
			{
				if (c[i].covered_cnt % 2 == 1)
					ans += s;
				else
					ans -= s;
			}
		}
		printf("%.8lf\n", ans);
	}
}