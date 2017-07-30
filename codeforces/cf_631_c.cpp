#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;
const int INF = 1e9 + 7;
int a[N];
int b[N];
pair<int, int>Q[N];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
		}
		stack<pair<int, int> >s;
		for (int i = 0; i < q; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			while (!s.empty() && s.top().second <= y)
				s.pop();
			s.push(make_pair(x, y));
		}
		vector<pair<int, int> >tar;
		while (!s.empty())
			tar.push_back(s.top()), s.pop();
		pair<int, int> cur = *(--tar.end());
		if (cur.first == 1)
			sort(a + 1, a + 1 + cur.second);
		else
			sort(a + 1, a + 1 + cur.second, cmp);
		int flag = cur.first;
		for (int i = n; i > cur.second; i--)
			b[i] = a[i];
		int l = 1, r = cur.second;
		for (int i = tar.size(); i >= 1; i--)
		{
			for (int j = tar[i].second; j >= tar[i - 1].second + 1; j--)
			{
				if (tar[i].first != flag)
					b[j] = a[l++];
				else
					b[j] = a[r--];
			}
		}
		for (int i = tar[0].second; i >= 1; i--)
			if (tar[0].first != flag)
				b[i] = a[l++];
			else
				b[i] = a[r--];
		for (int i = 1; i <= n; i++)
		{
			if (i != 1)
				printf(" ");
			printf("%d", b[i]);
		}
		printf("\n");
	}
}