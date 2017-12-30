#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		int Min = 1e9 + 7;
		for (int i = 0; i < n; i ++)
		{
			int x;
			cin >> x;
			v.push_back(x);
			Min = min(x, Min);
		}
		int cur = -1;
		int dis = 1e9;
		for (int i = 0; i < n; i ++)
		{
			if (v[i] != Min)
				continue;
			if (cur == -1)
				cur = i;
			else
			{
				dis = min(i - cur, dis);
				cur = i;
			}
		}
		cout << dis << endl;
	}
}