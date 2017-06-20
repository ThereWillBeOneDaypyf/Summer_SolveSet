#include<bits/stdc++.h>

using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[100];

void tran(string s)
{
	for(int i =0 ;i<s.length();i++)
		a[i] = s[i] - '0';
}
bool judge(string s)
{
	int cnt = 0;
	if(a[0] != 1)
		return false;
	for(int i =0 ;i<s.length();i++)
	{
		if(a[i]!=1 && a[i] != 8)
			return false;
		if(a[i] == 1)
			cnt = 0;
		else 
		{
			cnt ++;
			if(cnt >= 3)
				return false;
		}
	}
	return true;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		tran(s);
		if(judge(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
