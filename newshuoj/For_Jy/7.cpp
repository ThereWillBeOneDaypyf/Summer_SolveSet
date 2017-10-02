#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

long long dfs(int n, int m)
{
	if (n == 0 || n == 1 || m == 0 || m == 1)
		return 1;
	if (n > m)
		return dfs(m, m);
	else return dfs(n - 1, m) + dfs(n, m - n);
}

int main()
{
	int n;
	while (cin >> n)
		cout << dfs(n, n) << endl;
}