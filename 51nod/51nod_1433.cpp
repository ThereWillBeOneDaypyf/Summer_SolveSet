#include<bits/stdc++.h>
using namespace std;

int a[10];
int main()
{
	int n;
	while (cin >> n)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a[x] ++;
		}
		if (a[5] < 9 && a[0])
			cout << 0 << endl;
		else if (a[5] >= 9 && a[0])
		{
			for (int i = 0; i < a[5] / 9; i++)
				for (int j = 0; j < 9; j++)
					cout << 5;
			for (int i = 0; i < a[0]; i++)
				cout << 0;
			cout << endl;
		}
		else
			cout << - 1 << endl;
	}
}