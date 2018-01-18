#include<bits/stdc++.h>
using namespace std;

int cnt[10];
string s1, s2;
string ans;
int flag = 0;
void dfs(int pos, string cur, int eq)
{
	if (pos >= s1.size())
	{
		ans = cur;
		flag = 1;
		return;
	}
	if (flag)
		return;
	if (eq)
	{
		if (cnt[s2[pos] - '0'] != 0)
		{
			cnt[s2[pos] - '0'] --;
			dfs(pos + 1, cur  + s2[pos], 1);
			cnt[s2[pos] - '0'] ++;
		}
		for (int i = s2[pos] - '0' - 1; i >= 0; i--)
		{
			if (!cnt[i])
				continue;
			cnt[i] --;
			dfs(pos + 1, cur + (char)(i + '0'), 0);
			cnt[i] ++;
		}
	}
	else
	{
		for (int i = 9; i >= 0; i--)
		{
			if (!cnt[i])
				continue;
			cnt[i] --;
			dfs(pos + 1, cur + (char)(i + '0'), 0);
			cnt[i] ++;
		}
	}
}

int main()
{
	while (cin >> s1 >> s2)
	{
		memset(cnt, 0, sizeof(cnt));
		for (auto x : s1)
			cnt[x - '0'] ++;
		if (s2.length() > s1.length())
		{
			for (int i = 9; i >= 0; i--)
			{
				for (int j = 0; j < cnt[i]; j++)
					cout << i;
			}
			cout << endl;
		}
		else
		{
			flag = 0;
			dfs(0, "", 1);
			cout << ans << endl;
		}
	}
}