#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int n, a, b;
int h[20];
int cnt = 1e5 + 8;
void dfs(int pos, int t)
{
	if (pos > n)
	{
		for (int i = 1; i <= n; i++)
			if (h[i] >= 0)
				return;
		cnt = min(cnt, t);
		return;
	}
	if (h[pos] >= 0 || h[pos - 1] >= 0)
	{
		h[pos - 1] -= b;
		h[pos + 1] -= b;
		h[pos] -= a;
		dfs(pos, t + 1);
		h[pos - 1] += b;
		h[pos] += a;
		h[pos + 1] += b;
	}
	dfs(pos + 1, t);
}
int main()
{
	while (cin >> n >> a >> b)
	{
		cnt = 1e5;
		for (int i = 1; i <= n; i++)
			cin >> h[i];
		int ans = h[1] / b + 1;
		h[1] -= ans * b;
		h[2] -= ans * a;
		h[3] -= ans * b;
		if (h[n] >= 0)
		{
			int temp = h[n] / b + 1;
			ans += temp;
			h[n] -= temp * b;
			h[n - 1] -= temp * a;
			h[n - 2] -= temp * b;
		}
		dfs(2, 0);
		if (cnt == 1e5)
			cnt = 0;
		cout << ans + cnt << endl;
	}
}