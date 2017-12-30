#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;

long long pre_sum[N];
long long sufix_sum[N];

int main()
{
	int T;
	int ka = 0;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		memset(pre_sum, 0, sizeof(pre_sum));
		memset(sufix_sum, 0, sizeof(sufix_sum));
		for (int i = 0; i < s.length(); i ++)
		{
			pre_sum[i + 1] = pre_sum[i];
			if (s[i] == 'Q')
				pre_sum[i + 1] ++;
		}
		for (int i = s.length() - 1; i >= 0; i --)
		{
			sufix_sum[i] = sufix_sum[i + 1];
			if (s[i] == 'Q')
				sufix_sum[i] ++;
		}
		long long ans = 0;
		for (int i = 0; i < s.length(); i++)
			if (s[i] == 'A')
				ans += pre_sum[i + 1] * sufix_sum[i];
		cout << "Case #" << ++ ka << ": ";
		cout << ans << endl;
	}
}