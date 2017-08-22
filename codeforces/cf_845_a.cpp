#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[2000];
int n;
bool judge()
{
	return a[n - 1] < a[n];
}
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < 2 * n; i++)
			cin >> a[i];
		sort(a, a + n * 2);
		if (judge())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}