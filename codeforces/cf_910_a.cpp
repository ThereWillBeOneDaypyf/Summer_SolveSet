#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, d;
	while (cin >> n >> d)
	{
		string s;
		cin >> s;
		vector<int> v;
		for (int i = 0; i < s.length(); i++)
			if (s[i] == '1')
				v.push_back(i + 1);
		int cur = 0;
		int ans = 0;
		int ok = 1;
		while (cur < n)
		{
			int flag = 0;
			for (int j = cur + d; j > cur; j --)
				if (s[j] == '1')
				{
					flag = 1;
					ans ++;
					cur = j;
					break;
				}
			if (!flag)
			{
				ok = 0;
				break;
			}
			if (cur == n - 1)
				break;
		}
		if (ok)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
}