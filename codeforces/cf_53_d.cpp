#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[1000];
int b[1000];
vector<pair<int, int> > ans;
void find(int pos, int tar)
{
	if (b[pos] == tar)
		return;
	find(pos + 1, tar);
	swap(b[pos], b[pos + 1]);
	ans.push_back(make_pair(pos, pos + 1));
}
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		ans.clear();
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == b[i])
				continue;
			find(i, a[i]);
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].first << " " << ans[i].second << endl;
	}
}