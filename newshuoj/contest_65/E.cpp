#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios :: sync_with_stdio(false);
	int T;
	int ka = 0;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		cout << "Case #" << ++ ka << ": ";
		if (v[0] >= 3 || v[1] >= 3)
			cout << "Bad Problem Set" << endl;
		else if (v[2] <= 2)
			cout << "Bad Problem Set" << endl;
		else
		{
			int flag = 1;
			for (int i = 2; i < n - 1; i ++)
			{
				if (v[i] - v[i - 1] > 2)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
				cout << "Good Problem Set" << endl;
			else
				cout << "Bad Problem Set" << endl;
		}
	}
}