#include <bits/stdc++.h>
using namespace std;

bool check(int val)
{
	string s = to_string(val);
	vector<int> v(10, 0);
	for(auto ele : s)
	{
		v[ele - '0'] ++;
		if(v[ele - '0'] > 1)
			return false;
	}
	return true;
}

int main()
{
	int l, r;
	while(cin >> l >> r)
	{
		int flag = -1;
		for(int i = l; i <= r; i ++)
		{
			if(check(i))
			{
				flag = i;
				break;
			}
		}
		cout << flag << endl;
	}
}
