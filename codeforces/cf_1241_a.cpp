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
		if(n == 2)
			cout << 2 << endl;
		else if(n == 1)
			cout << 2 << endl;
		else 
			cout << n % 2 << endl;
	}
}
