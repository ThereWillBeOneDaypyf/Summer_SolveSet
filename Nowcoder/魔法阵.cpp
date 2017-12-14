#include<bits/stdc++.h>
using 	namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for (auto op : s1)
			cnt[op - 'A'] ++;
		long long ans = 0;
		for (auto op : s2)
			ans += cnt[op - 'A'];
		ans *= s1.length();
		cout << ans << endl;
	}
}