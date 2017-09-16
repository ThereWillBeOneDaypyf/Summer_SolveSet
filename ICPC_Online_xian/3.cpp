#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		string s;
		cin >> s;
		for(int i = 0; i< 233;i++)
		{
			cout << 1;
			for(int j = 1;j<s.length();j++)
				cout << 0;
		}
		cout << endl;
	}
}
