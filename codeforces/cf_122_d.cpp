#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n,k;
	string s;
	while(cin >> n >> k)
	{
		cin >> s;
		if(k == 0)
		{
			cout << s << endl;
			continue;
		}
		for(int i = 0;i<s.length()-1;i++)
		{
			if(s[i] == '4' && s[i+1] == '7')
			{
				k -- ;
				if((i+1) % 2)
					s[i+1] = '4';
				else
					s[i] = '7';
				if(k == 0)
					break;
			}
			if(i == 0)
				continue;
			else
			{
				if((i+1) % 2 && s[i-1] == '4' && s[i] == '4' && s[i+1] == '7')
				{
					if(k % 2)
						s[i] = '7';
					break;
				}
				else if((i+1) % 2 == 0 && s[i-1] == '4' && s[i] == '7' && s[i+1] == '7')
				{
					if(k % 2)
						s[i] = '4';
					break;
				}
			}
		}
		cout << s << endl;
	}
}
