#include<bits/stdc++.h>
using namespace std;

int cnt[26];

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		vector<string> v;
		vector<int> dif[2501];
		string s;
		cin >> s;
		v.push_back(s);
		memset(cnt, 0, sizeof(cnt));
		int multi = 0;
		for (auto op : s)
		{
			cnt[op - 'a'] ++;
			if (cnt[op - 'a'] > 1)
				multi = 1;
		}
		int flag = 0;
		for (int i = 1; i < n; i++)
		{
			cin >> s;
			int temp[26];
			v.push_back(s);
			memset(temp, 0, sizeof(temp));
			for (auto op : s)
				temp[op - 'a'] ++;
			for (int j = 0; j < 26; j++)
			{
				// cout << temp[j] << " " << cnt[j] << endl;
				if (temp[j] != cnt[j])
				{
					cout << -1 << endl;
					return 0;
				}
			}
			for (int j = 0; j < k; j++)
				if (v[0][j] != s[j])
					dif[i].push_back(j);
			if (dif[i].size())
				flag = 1;
			if (dif[i].size() > 4)
			{
				cout << -1 << endl;
				return 0;
			}
		}
		if (!flag)
		{
			swap(v[0][0], v[0][1]);
			cout << v[0] << endl;
			return 0;
		}
		for (int i = 0; i < k; i++)
		{
			for (int j =  i + 1; j < k; j++)
			{
				swap(v[0][i], v[0][j]);
				int ok = 1;
				for (int kk = 1; kk < n; kk++)
				{
					int needchange = 0;
					if (v[kk][i] != v[0][i]) needchange ++;
					if (v[kk][j] != v[0][j]) needchange ++;
					for (auto pos : dif[kk])
						if (pos != i && pos != j && v[kk][pos] != v[0][pos])
							needchange ++;
					if ((needchange == 0 && multi == 0) || (needchange != 0 && needchange != 2))
					{
						ok = 0;
						break;
					}
				}
				if (ok)
				{
					cout << v[0] << endl;
					return 0;
				}
				swap(v[0][i], v[0][j]);
			}
		}
		cout << -1 << endl;
	}
}