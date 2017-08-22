#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


const long long tar =  4228120576;

int main()
{
	ios :: sync_with_stdio(false);
	string s;
	while(cin >> s)
	{
		if(s.length() > 10)
			cout << "TAT" << endl;
		else
		{
			long long ans = 0;
			for(int i = 0;i<s.length();i++)
				ans = ans * 10 + s[i] - '0';
			if(ans > tar)
				cout << "TAT" << endl;
			else
			{
				if(ans == 0)
				{
					cout << "TAT" << endl;
					continue;
				}
				int cnt = 0;
				while(ans != 1)
				{
					cnt ++;
					ans = sqrt(ans);
				}
				cout << cnt << endl;
			}	
		}
	}
}
