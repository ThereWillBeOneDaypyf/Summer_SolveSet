#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

vector<string> s;

int main()
{
	int n;
	while(cin >> n)
	{
		string str;
		int flag = 0;
		for(int i = 0;i<n;i++)
		{
			cin >> str;
			for(int j = 0;j<4;j++)
				if(!flag && str[j] == 'O' && str[j+1] == 'O')
				{
					str[j] = '+',str[j+1] = '+';
					flag = 1;
				}
			s.push_back(str);
		}
		if(!flag)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			for(int i = 0;i<n;i++)
				cout << s[i] << endl;
		}
	}
}
