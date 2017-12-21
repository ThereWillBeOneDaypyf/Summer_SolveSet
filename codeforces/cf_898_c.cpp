#include<bits/stdc++.h>
using namespace std;

bool judge(string tar, string opt)
{
	if (tar.length() > opt.length())
		return true;
	for (int i = tar.length() - 1, j = opt.length() - 1; i >= 0; i--, j--)
		if (tar[i] != opt[j])
			return true;
	return false;
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		int cnt = 0;
		map<string, int> id;
		set<string> v[22];
		for (int i = 0; i < n; i++)
		{
			string name;
			int c;
			cin >> name >> c;
			if (!id.count(name))
				id[name] = ++ cnt;
			for (int j = 0; j < c; j ++)
			{
				string s;
				cin >> s;
				v[id[name]].insert(s);
			}
		}
		vector<string>G[22];
		int all = 0;
		for (int i = 1; i <= n; i++)
		{
			auto it = v[i].begin();
			for (auto j = it; j != v[i].end(); j++)
			{
				int flag = 1;
				for (auto k = v[i].begin(); k != v[i].end(); k ++)
				{
					if (j == k)
						continue;
					if (!judge(*j, *k))
					{
						flag = 0;
						break;
					}
				}
				if (flag)
					G[i].push_back(*j);
			}
			if (G[i].size())
				all ++;
		}
		cout << all << endl;
		for (auto temp : id)
		{
			if (G[temp.second].size() == 0)
				continue;
			cout << temp.first << " " << G[temp.second].size();
			for (auto ans : G[temp.second])
				cout << " " << ans;
			cout << endl;
		}
	}
}