#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> ans;
		for (int i = 2;; i++)
		{
			if (i * i / 2 > n)
				break;
			if ((2 * n) % i)
				continue;
			int tar = 2 * n / i;
			tar += (1 - i);
			if (tar <= 0)
				continue;
			if (tar % 2)
				continue;
			tar /= 2;
			ans.push_back(tar);
		}
		sort(ans.begin(), ans.end());
		if (ans.size() == 0)
		{
			cout << "No Solution" << endl;
			continue;
		}
		for (auto v : ans)
			cout << v << endl;
	}
}