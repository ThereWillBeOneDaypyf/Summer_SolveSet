#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	string s;
	while(cin >> n >> k >> s) 
	{
		if(k == 0)
			cout << s << endl;
		else 
		{
			if(s.size() == 1)
				s[0] = '0';
			else 
			{
				if(s[0] != '1')
					k --;
				s[0] = '1';
			}
			for(int i = 1; i < s.length(); i++) 
			{
				if(k == 0)
					break;
				else 
				{
					if(s[i] == '0')
						continue;
					k --;
					s[i] = '0';
				}
			}
			cout << s << endl;
		}
	}
}
