#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	map<char, int>m;
	int n, k;
	while (cin >> n >> k)
	{
		string s;
		cin >> s;
		for (int i = 0; i < n; i++)
			m[s[i]] ++;
		int flag = 1;
		for (map<char, int> :: iterator it = m.begin(); it != m.end(); it++)
		{
			if (it -> second > k)
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}