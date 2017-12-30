#include<bits/stdc++.h>
using namespace std;

int a[26];

long long gethash()
{
	long long sum = 0;
	for (int i = 0; i < 26; i++)
		if (a[i])
			sum += (1 << i);
	return sum;
}
bool judge(long long curstatus)
{
	int cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		long long first = (1 << i) & curstatus;
		if (first != 0)
			cnt ++;
	}
	if (cnt == 1)
		return true;
	return false;
}
int n;

int main()
{
	while (cin >> n)
	{
		long long curstatus = (1 << 26) - 1;
		int flag = 0;
		int ans = 0;
		int ok = 0;
		for (int j = 0; j < n - 1; j ++)
		{
			string op, s;
			cin >> op >> s;
			if (ok)
				continue;
			if (op ==  "." || op == "?")
			{
				for (int i = 0; i < 26; i++)
					a[i] = 1;
				for (auto x : s)
					a[x - 'a'] = 0;
				long long temp = gethash();
				curstatus &= temp;
				if (flag && op == "?")
					ans ++;
				if (!flag && judge(curstatus))
					flag = 1;
			}
			else if (op == "!")
			{
				memset(a, 0, sizeof(a));
				for (auto x : s)
					a[x - 'a'] = 1;
				long long temp = gethash();
				curstatus &= temp;
				if (flag)
					ans ++;
				if (!flag && judge(curstatus))
					flag = 1;
			}
			// else if (op == "?")
			// {
			// 	memset(a, 0, sizeof(a));
			// 	for (auto x : s)
			// 		a[x - 'a'] = 1;
			// 	long long temp = gethash();
			// 	if (flag && temp != curstatus)
			// 		ans ++;
			// 	if (temp == curstatus)
			// 		ok = 1;
			// }
		}
		string x, y;
		cin >> x >> y;
		cout << ans << endl;
	}
}