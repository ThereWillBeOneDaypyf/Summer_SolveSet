// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
// #include<vector>
// #include<cmath>
// #include<cstdio>
// #include<cstring>
// #include<string>
// #include<stack>
// #include<map>
// #include<set>
// using namespace std;

// //thanks to pyf ...
// //thanks to qhl ...

// #define INF 0x3f3f3f3f
// #define CLR(x,y) memset(x,y,sizeof(x))
// #define mp(x,y) make_pair(x,y)
// typedef pair<int, int> PII;
// typedef long long ll;

// const int N = 1e6 + 5;
// double R;
// struct Point
// {
// 	double x, y;
// 	double l, r;
// 	bool not_reach;
// 	void cal()
// 	{
// 		ll res = R * R - y * y;
// 		if (res < 0)
// 		{
// 			not_reach = true;
// 			return;
// 		}
// 		else
// 			not_reach = false;
// 		double temp = sqrt(R * R - y * y);
// 		l = (double)x - temp , r = (double) x + temp;
// 	}
// 	bool operator < (const Point &rhs) const
// 	{
// 		return r < rhs.r || (r == rhs.r && l > rhs.l);
// 	}
// } p[N];


// int main()
// {
// 	int n;
// 	int ka = 0;
// 	while (cin >> n >> R)
// 	{
// 		if (n == 0 && R == 0)
// 			break;
// 		int flag = 0;
// 		if (R < 0)
// 			flag = 1;
// 		for (int i = 0 ; i < n; i++)
// 		{
// 			cin >> p[i].x >> p[i].y;
// 			if (p[i].y < 0)
// 				flag = 1;
// 			p[i].cal();
// 			if (p[i].not_reach)
// 				flag = 1;
// 		}
// 		cout << "Case " << ++ka << ": ";
// 		if (flag)
// 		{
// 			cout << -1 << endl;
// 			continue;
// 		}
// 		sort(p, p + n);
// 		int ans = 1;
// 		double cur = p[0].r;
// 		for (int i = 1; i < n; i++)
// 		{
// 			if (p[i].l > cur)
// 			{
// 				ans ++;
// 				cur = p[i].r;
// 			}
// 			// else if (p[i].r < cur)
// 			// 	cur = p[i].r;
// 		}

// 		cout << ans << endl;
// 	}
// 	return 0;
// }

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
double R;
struct Point
{
	double x, y;
	double l, r;
	bool not_reach;
	void cal()
	{
		ll res = R * R - y * y;
		if (res < 0)
		{
			not_reach = true;
			return;
		}
		else
			not_reach = false;
		double temp = sqrt(R * R - y * y);
		l = (double)x - temp , r = (double) x + temp;
	}
	bool operator < (const Point &rhs) const
	{
		return r < rhs.r || (r == rhs.r && l < rhs.l);
	}
} p[N];


int main()
{
	int n;
	int ka = 0;
	while (cin >> n >> R)
	{
		if (n == 0 && R == 0)
			break;
		int flag = 0;
		if (R < 0)
			flag = 1;
		for (int i = 0 ; i < n; i++)
		{
			cin >> p[i].x >> p[i].y;
			p[i].cal();
			if (p[i].y < 0)
				flag = 1;
			if (p[i].not_reach)
				flag = 1;
		}
		cout << "Case " << ++ka << ": ";
		if (flag)
		{
			cout << -1 << endl;
			continue;
		}
		sort(p, p + n);
		int ans = 1;
		double cur = p[0].r;
		for (int i = 1; i < n; i++)
		{
			if (p[i].l > cur)
			{
				ans ++;
				cur = p[i].r;
			}
			else if (p[i].r < cur)
				cur = p[i].r;
		}
		cout << ans << endl;
	}
}