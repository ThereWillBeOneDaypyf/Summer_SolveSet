#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

vector<string>tar;

bool judge(string s1, string s2)
{
	if (s1.length() > s2.length())
		return false;
	for (int i = 0; i < s1.length(); i++)
		if (s1[i] != s2[i])
			return false;
	return true;
}
int main()
{
	ios :: sync_with_stdio(false);
	string s;
	while (cin >> s)
	{
		tar.clear();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string x;
			cin >> x;
			tar.push_back(x);
		}
		sort(tar.begin(), tar.end());
		tar.push_back(s);
		for (int i = 0; i < tar.size(); i++)
		{
			if (judge(s, tar[i]))
			{
				cout << tar[i] << endl;
				break;
			}
		}
	}
}