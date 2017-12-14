#include<bits/stdc++.h>
using namespace std;


int main()
{
	int p;
	while (cin >> p)
	{
		vector<int> a, b;
		int cnt[10];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 6; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < 6; i++)
		{
			int x;
			cin >> x;
			b.push_back(x);
		}
		for (auto p1 : a)
		{
			for (auto p2 : b)
			{
				cnt[(p1 + p2) % p] ++;
			}
		}
		int flag = 1;
		for (int i = 1; i < p; i++)
			if (cnt[0] != cnt[i])
				flag = 0;
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}