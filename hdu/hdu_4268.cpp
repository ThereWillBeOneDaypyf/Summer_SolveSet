#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 8;

struct Node
{
	int w, h;
	bool operator < (const Node &rhs) const
	{
		return w < rhs.w || (w == rhs.w && h < rhs.h);
	}
} a[N], b[N];

int main()
{
	int T;
	scanf("%d", &T);
	multiset<int>s;
	multiset<int> :: iterator it;
	while (T--)
	{
		int n;
		s.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].h, &a[i].w);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &b[i].h, &b[i].w);
		sort(a, a + n);
		sort(b, b + n);
		int j = 0;
		int ans = 0 ;
		for (int i = 0 ; i < n; i++)
		{
			while (j < n)
			{
				if (a[i].w >= b[j].w)
					s.insert(b[j++].h);
				else
					break;
			}
			if (s.empty())
				continue;
			s.upper_bound(a[i].h);
			if (it == s.begin())
				continue;
			else
			{
				ans ++;
				s.erase(--it);
			}
		}
		printf("%d\n", ans);
	}
}