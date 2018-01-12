#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

struct Node
{
	int t, a, id;
	bool operator < (const Node & rhs) const
	{
		return t < rhs.t;
	}
};

int n, m;
vector<Node> v;
int vis[N];
bool judge(int mid)
{
	int temp = m;
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].a >= mid && temp >= v[i].t)
		{
			cnt ++;
			temp -= v[i].t;
			vis[v[i].id] = 1;
		}
		if (cnt == mid)
			break;
	}
	if (cnt >= mid)
		return true;
	else
		return false;
}
int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			int t, a;
			cin >> a >> t;
			v.push_back({t, a, i + 1});
		}
		sort(v.begin(), v.end());
		int temp = m;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i].t <= temp)
			{
				cnt ++;
				temp -= v[i].t;
			}
			else
				break;
		}
		int l = 0, r = cnt;
		vector<int> ans;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (judge(mid))
			{
				l = mid + 1;
				ans.clear();
				for (int i = 1; i <= n; i++)
					if (vis[i])
						ans.push_back(i);
			}
			else
				r = mid - 1;
		}
		cout << ans.size() << endl;
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			if (i)
				cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}