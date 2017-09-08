#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 9;

vector<pair<int, int> >v;
long long c[N];
int pos[N];
int ans[N];
int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) == 2)
	{
		v.clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", c + i);
			v.push_back(make_pair(c[i], i));
		}
		memset(pos, 0, sizeof(pos));
		sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int>b) {return a.first > b.first;});
		int p = 0;
		for (int i = 1; i <= n; i++)
		{
			if (pos[i])
				continue;
			while (p < v.size() && v[p].second > k + i)
			{
				pos[v[p].second - k] = v[p++].second;
			}
			pos[i] = v[p++].second;
		}
		long long sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += 1LL * c[pos[i]] * (i + k - pos[i]);
			ans[pos[i]] = i;
		}
		printf("%lld\n", sum);
		for (int i = 1; i <= n; i++)
		{
			if (i != 1)
				printf(" ");
			printf("%d", ans[i] + k);
		}
		printf("\n");
	}
}