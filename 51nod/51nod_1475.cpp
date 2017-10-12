#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3 + 7;

vector<int>v[N];

int main()
{
	int n, H;
	while (scanf("%d%d", &n, &H) == 2)
	{
		for (int i = 0; i < N; i++)
			v[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int h, p;
			scanf("%d%d", &h, &p);
			v[min(n, H - h)].push_back(p);
		}
		int cur = 0;
		int ans = 0;
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 1; i <= n; i++)
		{
			while (q.size() >= i)
			{
				cur -= q.top();
				q.pop();
			}
			for (auto temp : v[i])
			{
				cur += temp;
				q.push(temp);
			}
			while (q.size() > i + 1)
			{
				cur -= q.top();
				q.pop();
			}
			ans = max(ans, cur);
		}
		printf("%d\n", ans);
	}
}
