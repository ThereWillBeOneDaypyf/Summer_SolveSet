#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	string s;
	while (cin >> a >> b >> s)
	{
		int flag = 1;
		if (s.length()  != a + b + 1)
			flag = 0;
		int cnt = 0;
		for (auto op : s)
		{
			if (op == '-')
				cnt ++;
			else if (!(op >= '0' && op <= '9'))
				flag = 0;
		}
		if (cnt != 1)
			flag = 0;
		int pos = -1;
		for (int i = 0; i < s.length(); i ++)
			if (s[i] == '-')
				pos = i;
		if (pos != a)
			flag = 0;
		if (!flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}