// #include<bits/stdc++.h>
// using namespace std;

// //thanks to pyf ...
// //thanks to qhl ...

// const int MOD = 1e9 + 7;

// long long pow_mod(int x)
// {
// 	if (x == 0)
// 		return 1;
// 	long long temp = pow_mod(x / 2);
// 	temp = temp * temp % MOD;
// 	if (x % 2)
// 		temp = temp * 2 % MOD;
// 	return temp;
// }
// int main()
// {
// 	ios :: sync_with_stdio(false);
// 	int n;
// 	while (cin >> n)
// 	{
// 		for (int i = 1; i < n; i++)
// 		{
// 			int u, v;
// 			cin >> u >> v;
// 		}
// 		long long ans = 1LL * (n + 1) * pow_mod(n - 2) % MOD;
// 		ans %= MOD;
// 		cout << ans << endl;
// 	}
// }
