#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	string s;
	while (cin >> n >> s)
	{
		long long ans = 0;
		for (int i = 0; i != s.length(); i++)
			if (s[i] == 'B')
			{
				ans += (long long) pow(2, i);
			}
		cout << ans << endl;
	}
}