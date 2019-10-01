#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin >> q;
	while(q--) 
	{
		int n;
		cin >> n;
		int sum = 0;
		for(int i = 0;i < n; i ++)
		{
			int x;
			cin >> x;
			sum += x;
		}
		cout << (sum + n - 1) / n << endl;
	}
}
