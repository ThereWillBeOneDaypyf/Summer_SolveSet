#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

map<int, int>l;
int main()
{
	string s;
	while (cin >> s)
	{
		int cnt[2];
		memset(cnt, 0, sizeof(cnt));
		int ans = 0;
		l.clear();
		for (int i = 0; i < s.length(); i++)
		{
			cnt[s[i] - '0'] ++;
			if (cnt[0] == cnt[1])
				ans = max(ans, i + 1);
			else
			{
				int dif = cnt[0] - cnt[1];
				if (!l.count(dif))
					l[dif] = i;
				else
					ans = max(ans, i - l[dif]);
			}
		}
		cout << ans << endl;
	}
}