#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

int main()
{
	string s;
	while (cin >> s)
	{
		for (int i = 0; i < s.length(); i += 2)
			cout << s[i];
		cout << endl;
	}
}