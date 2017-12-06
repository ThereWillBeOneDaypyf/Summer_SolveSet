#include<bits/stdc++.h>
using namespace std;

vector<int> v;


int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		int flag = 1;
		int G = v[0];
		for (int i = 1; i < v.size(); i++)
		{
			G = __gcd(G, v[i]);
		}
		if (v[0] != G)
			cout << -1 << endl;
		else
		{
			vector<int>ans;
			for (int i = 0; i < n; i++)
			{
				ans.push_back(v[i]);
				ans.push_back(v[0]);
			}
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++)
			{
				if (i)
					cout << " ";
				cout << ans[i];
			}
			cout << endl;
		}
	}
}