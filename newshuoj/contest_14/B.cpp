#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int a[100];

int main()
{
	int ret = 0;
	string s;
	int T;
	cin >> T;
	while(T--)
	{
		cin >> s;
		ret = 0;
		for(int i =0;i<s.length();i++)
			a[i] = s[i] - '0';
		for(int i =0;i<s.length();i++)
			ret = (ret * 10 + a[i]) % 13;
		if(ret)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}
