#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 7;

int a[N];

int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> x, y;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i ++)
		{
			int t;
			cin >> t;
			x.push_back(t);
			a[t] = 1;
		}
		for (int j = 0; j < n; j ++)
		{
			int t;
			cin >> t;
			y.push_back(t);
			a[t] = 1;
		}
		int cnt = 0;
		for (auto p : x)
		{
			for (auto q : y)
			{
				if ((p ^ q) < N && a[(p ^ q)])
					cnt ++;
			}
		}
		cout << "Case #" << ++ ka << ": ";
		if (cnt % 2)
			cout << "OneDay" << endl;
		else
			cout << "CSL" << endl;
	}
}