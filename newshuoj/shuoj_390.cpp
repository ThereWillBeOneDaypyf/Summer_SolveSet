#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n;
	while(cin >> n)
	{
		string s;
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			cin >> s;
			if(s[0] == 'X')
				ans ++;
			else
				ans --;
		}
		cout << ans << endl;
	}
}
