#include<bits/stdc++.h>
using namespace std;


int main()
{
	int  T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		int k ;
		cin >> k;
		string s;
		cin >> s;
		long long ans = 0;
		long long base = pow(2, k - 1);
		for (int i = 0; i < min(k, (int)s.length()); i ++)
		{
			ans *= 2;
			ans += s[i] - '0';
		}
		long long cur = ans;
		for (int i = k; i < s.length(); i++)
		{
			long long temp = cur - (s[i - k] - '0') * base;
			temp *= 2;
			temp += s[i] - '0';
			ans = max(ans, temp);
			cur = temp;
		}
		cout << "Case #" << ++ ka << ": ";
		cout << ans << endl;
	}
}