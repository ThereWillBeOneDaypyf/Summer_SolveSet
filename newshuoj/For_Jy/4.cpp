#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	vector<int> v;
	v.clear();
	int x;
	while (cin >> x)
		if (!x)
			break;
		else
			v.push_back(x);
	int cnt = 0;
	for (auto x : v)
		for (auto y : v)
			if (y == 2 * x)
				cnt ++;
	cout << cnt << endl;
}