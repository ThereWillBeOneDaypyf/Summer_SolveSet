#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int cnt[100];
int main()
{
	int n;
	string s;
	while (cin >> n >> s)
	{
		memset(cnt, 0, sizeof(cnt));
		long long sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			sum += (s[i] - '0');
			cnt[s[i] - '0'] ++;
		}
		if (sum >= n)
			cout << 0 << endl;
		else
		{
			long long need = n - sum;
			long long ans = 0;
			for (int i = 0; i < 10; i++)
			{
				if (need <= (9 - i) * cnt[i])
				{
					ans += ceil(1.0 * need / (9 - i));
					break;
				}
				else
				{
					ans += cnt[i];
					need -= (9 - i) * cnt[i];
				}
			}
			cout << ans << endl;
		}
	}
}