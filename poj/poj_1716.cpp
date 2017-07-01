#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

struct Edge
{
	int l, r;
	bool operator < (const Edge &rhs) const
	{
		return r < rhs.r || (r == rhs.r && l < rhs.l);
	}
} a[N];

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i].l >> a[i].r;
		sort(a, a + n);
		int lint = a[0].r - 1, rint = a[0].r;
		int ans = 2;
		for (int i = 1; i < n; i++)
		{
			if (a[i].l <= lint)
				continue;
			else if (a[i].l <= rint)
			{
				lint = a[i].r;
				ans ++;
				swap(lint, rint);
			}
			else
			{
				ans += 2;
				lint = a[i].r - 1;
				rint = a[i].r;
			}
		}
		cout << ans << endl;
	}
}