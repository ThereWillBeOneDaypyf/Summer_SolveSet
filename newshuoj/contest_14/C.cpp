#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int T;
	cin >> T;
	cin.get();
	while(T--)
	{
		map<char,int>m;
		string s;
		getline(cin,s);
		for(int i = 0;i<s.length();i++)
		{
			m[s[i]] ++;
		}
		int flag = 0;
		for(int i =0 ;i<s.length();i++)
		{
			if(m[s[i]] == 1)
			{
				flag = 1;
				cout << s[i] << endl;
			   break;	
			}
		}
		if(!flag)
			cout << "*" << endl;
	}
}
