#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	string s;
	while(cin >> s)
	{
		int cnt_four = 0,cnt_seven = 0;
		for(int i = 0;i<s.length();i++)
			if(s[i] == '4')
				cnt_four ++;
			else if(s[i] == '7')
				cnt_seven ++;
		if(cnt_four == 0 && cnt_seven == 0)
			cout << -1 << endl;
		else if(cnt_four < cnt_seven)
			cout << 7 << endl;
		else
			cout << 4 << endl;
	}
}
