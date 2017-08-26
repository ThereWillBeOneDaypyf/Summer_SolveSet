#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

vector<int>v, a;
int main()
{
	int T;
	scanf("%d", &T);
	int ka = 0;
	while (T--)
	{
		int n;
		scanf("%d", &n);
		a.clear(), v.clear();
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			a.push_back(x);
		}
		v.push_back(a[0]);
		for (int i = 1; i < n; i++)
		{
			if (a[i] == 0)
			{
				int temp_pos = v.size() - 1;
				v.push_back(v[temp_pos] + 1);
				for (int i = temp_pos - 1; i >= 0; i--)
					v[i + 1] = v[i] + 1;
				v[0] = 0;
			}
			else
			{
				auto it = lower_bound(v.begin(), v.end(), a[i]);
				if (it == v.end())
					v.push_back(a[i]);
				else
					*it = a[i];
			}
			// for (auto temp : v)
			// 	cout << temp << " ";
			// cout << endl;
		}
		printf("Case #%d: %d\n", ++ka, v.size());
	}
}