#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

int a[N];
int vis[N];
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int Max = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= k; i++)
		{
			cin >> a[i];
			Max = max(a[i], Max);
		}
		int cur = 1;
		stack<int> st;
		for (int i = 1; i <= k; i++)
		{
			vis[a[i]] = 1;
			if (a[i] == cur)
			{
				cur ++;
				while (!st.empty() && st.top() == cur)
				{
					st.pop();
					cur ++;
				}
			}
			else
				st.push(a[i]);
		}
		if (vis[cur] && st.top() != cur)
			cout << -1 << endl;
		else
		{
			int curcnt = k;
			vector<int> v;
			for (int i = 1; i <= Max; i++)
			{
				if (!vis[i])
				{
					v.clear();
					while (!vis[i])
						v.push_back(i++);
					reverse(v.begin(), v.end());
					for (auto x : v)
						a[++curcnt] = x;
					i--;
				}

			}
			for (int i = n; i > Max; i--)
				a[++curcnt] = i;
			for (int i = k + 1; i <= n; i++)
			{
				vis[a[i]] = 1;
				if (a[i] == cur)
				{
					cur ++;
					while (!st.empty() && st.top() == cur)
						st.pop(), cur ++;
				}
				else
					st.push(a[i]);
			}
			if (!st.empty())
				cout << -1 << endl;
			else
			{
				for (int i = 1; i <= n; i++)
				{
					if (i != 1)
						cout << " ";
					cout << a[i];
				}
			}
			cout << endl;
		}
	}
}