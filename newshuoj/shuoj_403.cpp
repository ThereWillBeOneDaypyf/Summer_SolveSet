#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

int main()
{
	map<char,int>m;
	int T;
	cin >> T;
	getchar();
	while(T--)
	{
		string s;
		getline(cin,s);
		m.clear();
		for(int i =0 ;i<s.length();i++)
			m[s[i]] ++;
		map<char,int> :: iterator it;
		int i;
		for(i = 0;i<s.length();i++)
			if(m[s[i]] == 1)
				break;
		if(i == s.length())
			cout << "*" << endl;
		else
			cout << s[i] << endl;
	}
}
