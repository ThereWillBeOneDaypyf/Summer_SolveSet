#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to lmd ...

#define N 1000

int dp[N][N];
int a[N][N];

int main()
{
	int n;
	int T;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> a[i][j];
				if (i == n - 1) dp[i][j] = a[i][j];
			}
		}
		for (int i = n - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{
				dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + a[i][j];
			}
		}
		cout << dp[0][0] << endl;
	}
	return n;
}