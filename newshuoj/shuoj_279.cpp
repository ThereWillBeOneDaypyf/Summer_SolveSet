#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

int tar[N];

void change(int pos,int l)
{
	for(int i = pos; i < l;i++)
	{
		tar[i] = !tar[i];
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		for(int i = 0;i < s.length();i++)
			tar[s.length() - 1 - i ] = (s[i] == '-' ? 0 : 1);
		int ans =0 ;
		for(int i = 0;i < s.length();i++)
			if(!tar[i])
			{
				change(i,s.length());
				ans ++;
			}
		cout << ans << endl;
	}
}
