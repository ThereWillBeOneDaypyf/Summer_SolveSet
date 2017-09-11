#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
vector<int>v;
vector<int>tar;
void init()
{
	tar.clear();
}
int solve()
{
	v.clear();
	auto it = tar.begin();
	v.push_back(*it++);
	for (; it != tar.end(); it ++)
	{
		if (*it >= *v.rbegin())
			v.push_back(*it);
		else
		{
			auto pos = upper_bound(v.begin(), v.end(), *it);
			*pos = *it;
		}
	}
	return v.size();
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		init();
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			tar.push_back(x);
		}
		int ans = n - solve();
		reverse(tar.begin(), tar.end());
		ans = min(ans, n - solve());
		if (ans <= k)
			printf("A is a magic array.\n");
		else
			printf("A is not a magic array.\n");
	}
}
