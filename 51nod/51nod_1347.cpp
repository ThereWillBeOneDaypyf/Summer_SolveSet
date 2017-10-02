#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

bool judge(string s)
{
	for (int i = 0; i < s.length() / 2; i++)
		if (s[i] != s[i + s.length() / 2])
			return false;
	return true;
}
int main()
{
	string s;
	while (cin >> s)
	{
		if (s.length() % 2)
			cout << "NO" << endl;
		else if (judge(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}