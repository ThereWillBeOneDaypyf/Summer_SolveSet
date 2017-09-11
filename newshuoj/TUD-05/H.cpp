#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		vector<long long>v{a, b, c};
		sort(v.begin(), v.end());
		cout << "Scenario #" << ++ka << ":" << endl;
		if (v[0] + v[1] > v[2] && v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		cout << endl;
	}
}