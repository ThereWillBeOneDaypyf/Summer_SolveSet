#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int s, v1, v2, t1, t2;
	while (cin >> s >> v1 >> v2 >> t1 >> t2)
	{
		int ans1 = t1 * 2 + s * v1;
		int ans2 = t2 * 2 + s * v2;
		if (ans1 < ans2)
			cout << "First" << endl;
		else if (ans1 > ans2)
			cout << "Second" << endl;
		else
			cout << "Friendship" << endl;
	}
}