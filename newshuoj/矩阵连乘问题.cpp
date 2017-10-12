#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[50];
int dp[50][50];
int pos[50][50];
string tran(int x)
{
	string s = "";
	x ++;
	while (x)
	{
		s += '0' + x % 10;
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
vector<string>v;
void dfs(int l, int r)
{
	if (l == r)
	{
		v.push_back("A" + tran(l));
		return;
	}
	else
	{
		v.push_back("(");
		dfs(l, pos[l][r]);
		dfs(pos[l][r] + 1, r);
		v.push_back(")");
	}
}
int main()
{
	int n;
	int ka = 0;
	while (cin >> n)
	{
		for (int i = 0; i <= n; i++)
			cin >> a[i];
		cout << "Case " << ++ ka << endl;
		if (n == 1)
		{
			cout << 0 << " A1" << endl;
			continue;
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = 1e9;
		for (int i = 0; i <= n; i++)
			dp[i][i] = 0;
		// for (int i = 0; i < n - 1; i++)
		// {
		// 	dp[i][i + 1] = a[i] * a[i + 1] * a[i + 2]; // i row i + 1 row
		// 	//i k k + 1 j a[i] * a[k + 1] * a[r + 1]
		// }
		for (int i = 2; i <= n; i++)
		{
			for (int l = 0, r = l + i - 1; r < n; l ++, r ++)
			{
				dp[l][r] = dp[l][l] + dp[l + 1][r] + a[l] * a[l + 1] * a[r + 1];
				pos[l][r] = l;
				for (int k = l + 1; k <= r; k++)
				{
					int temp = dp[l][k] + dp[k + 1][r] + a[l] * a[k + 1] * a[r + 1];
					if (temp < dp[l][r])
					{
						dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
						pos[l][r] = k;
					}
				}
			}
		}
		cout << dp[0][n - 1] << " ";
		v.clear();
		dfs(0, n - 1);
		for (int i = 1; i < v.size() - 1; i++)
			cout << v[i];
		cout << endl;
	}
}
