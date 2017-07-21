#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3;

int a[N];
int sum = 0;
int n;
set<pair<int, int> > s;

void dfs(int pos, int sum1, int sum2, int sum3)
{
	if (sum1 > sum / 2 || sum2 > sum / 2 || sum3 > sum / 2)
		return;
	if (pos == n)
	{
		if (sum1 <= sum2 && sum2 <= sum3 && sum1 + sum2 > sum3)
			s.insert(make_pair(sum1, sum2));
		return;
	}
	dfs(pos + 1, sum1 + a[pos], sum2, sum3);
	dfs(pos + 1, sum1, sum2 + a[pos], sum3);
	dfs(pos + 1, sum1, sum2, sum3 + a[pos]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		s.clear();
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		dfs(0, 0, 0, 0);
		printf("%d\n", s.size());
	}
}