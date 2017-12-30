#include<bits/stdc++.h>
using namespace std;

int a[10000];
int dp[2000][2000];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (a[i] > a[j])
					ans ++;
			}
		}
		int flag ;
		if (ans % 2)
			flag = 1;
		else flag = 0;
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			int l, r;
			cin >> l >> r;
			long long temp = (r - l + 1) * (r - l) / 2;
			flag ^= (temp % 2);
			if (flag)
				cout << "odd" << endl;
			else
				cout << "even" << endl;
		}
	}
}