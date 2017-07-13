#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

int a[N];
int n;
bool judge()
{
	int i;
	for (i = 1; i < n; i++)
		if (a[i - 1] <= a[i])
			break;
	if (i == n)
		return true;
	for (i = 1; i < n; i++)
		if (a[i - 1] >= a[i])
			break;
	if (i == n)
		return true;
	for (int i = 1; i < n; i++)
		if (a[i - 1] != a[i])
			break;
	if (i == n)
		return true;
	for (i = 1; i < n; i++)
		if (a[i - 1] >= a[i])
			break;
	for (; i < n; i++)
		if (a[i - 1] != a[i])
			break;
	for (; i < n; i++)
		if (a[i - 1] <= a[i])
			break;
	if (i == n)
		return true;
	return false;
}

int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (!judge())
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}
