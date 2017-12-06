#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;


int pre_q[N];
int post_q[N];

int main()
{
	string s;
	while (cin >> s)
	{
		memset(pre_q, 0, sizeof(pre_q));
		memset(post_q, 0, sizeof(post_q));
		int n = s.length();
		for (int i = 1; i <= n; i++)
		{
			if (s[i - 1] == 'Q')
				pre_q[i] ++, post_q[i] ++;
		}
		for (int i = 1; i <= n; i ++)
			pre_q[i] += pre_q[i - 1];
		for (int i = n; i >= 1; i--)
			post_q[i] += post_q[i + 1];
		long long ans = 0;
		for (int i = 0; i < n; i++)
			if (s[i] == 'A')
				ans += pre_q[i] * post_q[i + 1];
		cout << ans << endl;
	}
}