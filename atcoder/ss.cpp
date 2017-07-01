#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

string s;


bool judge(int l)
{
	if(l % 2)
		return false;
	for(int i = 0 ;i<l/2;i++)
	{
		if(s[i] != s[i+l/2])
			return false;
	}
	return true;
}

int main()
{
	while(cin >> s)
	{
		int i;
		for(i = s.length()-1;i>0;i--)
		{
			if(judge(i))
				break;			
		}
		cout << i  << endl;
	}	
}
