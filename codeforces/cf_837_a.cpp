#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n;
	cin >> n;
	string s;
	int ans = 0;
	while(cin >> s)
	{
		int res = 0;
		for(int i = 0;i<s.length();i++)
			if(isupper(s[i]))
				res ++;
		ans = max(res,ans);
	}
	cout << ans << endl;
}
