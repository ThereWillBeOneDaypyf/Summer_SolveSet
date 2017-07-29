#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n;
	while (cin >> n)
	{
		set<int>s;
		map<int, int>l, r;
		int x;
		cin >> x;
		s.insert(x);
		l[x] = r[x] = 0;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> x;
			auto it = s.lower_bound(x);
			int ans ;
			if (it == s.begin())
			{
				l[*it] = 1;
				ans = *it;
			}
			else if (it == s.end())
			{
				it --;
				r[*it] = 1;
				ans = *it;
			}
			else if (!l[*it])
			{
				l[*it] = 1;
				ans = *it;
			}
			else
			{
				it --;
				r[*it] = 1;
				ans = *it;
			}
			s.insert(x);
			l[x] = r[x] = 0;
			if (i)
				printf(" ");
			printf("%d", ans);
		}
		printf("\n");
	}
}