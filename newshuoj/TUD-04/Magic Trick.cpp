#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
const int N = 1e6 + 7;
struct Node
{
	string s;
	int row;
};
string z[N];
int row[N];
int tot = 0;
vector<string>ans;
int dp[N];
int ka = 0;
vector<int>temp;
int dfs(int x)
{
	temp.clear();
	int i;
	for (i = x; i < tot; i += z[i].size())
	{
		if (row[i] == 3)
		{
			dp[i] = i;
			break;
		}
		else if (dp[i] != -2)
			break;
		temp.push_back(i);
	}
	if (i >= tot)
		i = -1;
	else i = dp[i];
	for (auto ac : temp)
	{
		dp[ac] = i;
	}
	return dp[x];
}
string x, s;
int main()
{
	// freopen("1.in", "r", stdin);
	// freopen("t.out", "w", stdout);
	int T;
	cin >> T;
	char op;
	cin >> op;
	while (T--)
	{
		tot = 0;
		for (int i = 0; i < N; i++)
			dp[i] = -2;
		int cnt = 0;
		map<int, int>m;
		while (1)
		{
			cnt ++;
			if (cnt > 3)
				break;
			getline(cin, s);
			for (int i = 0; i < s.length(); i++)
				if (!isalpha(s[i]))
					s[i] = ' ';
			for (int i = 0; i < s.length(); i++)
			{
				if (s[i] == ' ')
					continue;
				x.clear();
				while (i < s.length() && s[i] != ' ')
					x += tolower(s[i++]);
				z[tot] = x;
				row[tot++] = cnt;
			}
		}
		int flag = 0;
		cout << "Scenario #" << ++ ka << ":" << endl;
		ans.clear();
		for (int i = 0; i < tot; i++)
		{
			if (row[i] > 1)
				break;
			int res = dfs(i);
			if (!m.count(res))
			{
				m[res] = 1;
				if (res >= 0 && res < tot)
					ans.push_back(z[res]);
			}
			if (ans.size() > 3)
			{
				cout << "-too many-" << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			if (m.count(-1))
				cout << "-outside-" << endl;
			sort(ans.begin(), ans.end());
			for (auto temp : ans)
				cout << temp << endl;
		}
		cout << endl;
	}
	return 0;
}