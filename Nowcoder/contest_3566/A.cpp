#include <bits/stdc++.h>
using namespace std;

bool checkGood(int x)
{
	x %= 7;
	if(x == 0 || x == 4 || x == -3)
		return false;
	return true;
}

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> v(n);
		int len = 0;
		int m = 0;
		for(int i = 0;i < n; i ++)
		{
			cin >> v[i];
			if(checkGood(v[i]))
			{
				len ++;
			}
			else
			{
				m = max(m, len);
				len = 0;
			}
		}
		m = max(len, m);
		cout << m << endl;
	}
}
