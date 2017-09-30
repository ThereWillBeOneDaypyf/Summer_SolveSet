#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int>v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		int cnt = 0;
		for (auto x : v)
			for (auto y : v)
				if (__gcd(x, y) == 1) // 双下划线 求x,y公因数
					cnt ++ ;
		cout << cnt / 2 << endl;
	}
}
