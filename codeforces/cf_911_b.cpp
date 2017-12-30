#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, a, b;
	while (cin >> n >> a >> b)
	{
		int Max = 0;
		for (int i = 1; i < n; i++)
		{
			int ret = n - i;
			Max = max(Max, min(b / ret, a / i));
		}
		cout << Max << endl;
	}
}