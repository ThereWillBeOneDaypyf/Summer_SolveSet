#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	string s1,s2,s3;
	while(cin >> s1 >> s2 >> s3)
	{
		map<char,char>m;
		for(int i = 0;i<s1.length();i++)
		{
			m[toupper(s1[i])] = toupper(s2[i]);
			m[tolower(s1[i])] = tolower(s2[i]);
		}
		for(int i = 0;i<s3.length();i++)
		{
			if(isalpha(s3[i]))
				cout << m[s3[i]];
			else
				cout << s3[i];
		}
		cout << endl;
	}
}
