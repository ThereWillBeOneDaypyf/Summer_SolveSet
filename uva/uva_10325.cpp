#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;

long long a[20];
long long S[N];
long long solve(int n, int m)
{
	int tot = 0;
	S[tot++] = -1;
	for (int i = 0; i < m; i++)
	{
		int temp = tot;
		for (int j = 0; j < temp; j++)
		{
			if (abs(S[j] / __gcd(S[j], a[i]) * a[i]) > n)
				continue;
			S[tot++] = (-1) * S[j] / __gcd(abs(S[j]), a[i]) * a[i];
		}
	}
	long long ans = 0;
	for (int i = 1; i < tot; i++)
	{
		ans += n / S[i];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < m; i++)
			cin >> a[i];
		cout << n - solve(n, m) << endl;
	}
}