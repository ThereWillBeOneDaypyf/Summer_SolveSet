#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 8;

long long a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] = a[i - 1] + a[i];
			if (a[i] % 2)
				flag = 1;
		}
		if (flag)
			cout << "First" << endl;
		else
			cout << "Second" << endl;
	}
}