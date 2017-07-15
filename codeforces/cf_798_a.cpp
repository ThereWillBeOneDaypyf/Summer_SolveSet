#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	string s;
	while (cin >> s)
	{
		int cnt = 0;
		for (int i =  0; i < s.length(); i++)
		{
			if (s[i] != s[s.length() - 1 - i])
				cnt ++;
		}
		if (cnt / 2 == 1 || (cnt == 0 && s.length() % 2 == 1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}