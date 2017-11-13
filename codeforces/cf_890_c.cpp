#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	vector<int> l;
	int n;
	while (cin >> n)
	{
		vector<int> v;
		int ans = 0;
		multiset<int>s;
		s.insert(0);
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			auto pos = s.find(x);
			if (pos != s.end())
				s.erase(pos);
			else
				ans ++;
			s.insert(i);
		}
		cout << ans + 1 << endl;
	}
}