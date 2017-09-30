#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, p, k;
	while (cin >> n >> p >> k)
	{
		int st = p - k;
		int ed = p + k;
		if (st < 1)
			st = 1;
		if (ed > n)
			ed = n;
		if (st != 1)
			cout << "<< ";
		for (int i = st ; i <= ed; i++)
		{
			if (i == p)
				cout << "(" << i << ")";
			else cout << i;
			if (i != ed)
				cout << " ";
		}
		if (ed != n)
			cout << " >>";
		cout << endl;
	}
}