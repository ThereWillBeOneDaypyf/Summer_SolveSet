#include<bits/stdc++.h>
using namespace std;

int main()
{
	int h1, a1, c1;
	int h2, a2;
	while (cin >> h1 >> a1 >> c1 >> h2 >> a2)
	{
		vector<int> v;
		while (h2 > 0)
		{
			if (a1 >= h2)
			{
				v.push_back(1);
				break;
			}
			if (h1 <= a2)
			{
				v.push_back(0);
				h1 += c1;
				h1 -= a2;
			}
			else
			{
				h2 -= a1;
				h1 -= a2;
				v.push_back(1);
			}
		}
		cout << v.size() << endl;
		for (auto x : v)
		{
			if (x)
				cout << "STRIKE" << endl;
			else
				cout << "HEAL" << endl;
		}
	}
}