#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

int a[N];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans =  1;
		int cur = m;
		for (int i = 0; i < n; i++)
		{
			if (cur < a[i])
			{
				cur = m - a[i];
				ans ++;
			}
			else
				cur -= a[i];
		}
		cout << ans << endl;
	}
}