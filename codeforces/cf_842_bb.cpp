#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Node
{
	double x, y, r;
} a[N];

double get_dis(Node a, Node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main()
{
	ios :: sync_with_stdio(false);
	double r, d;
	while (cin >> r >> d)
	{
		Node o = {0, 0, 0};
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].r;
			double dis = get_dis(o, a[i]);
			if (dis - a[i].r >= r - d && dis + a[i].r <= r)
				ans ++;
		}
		cout << ans << endl;
	}
}