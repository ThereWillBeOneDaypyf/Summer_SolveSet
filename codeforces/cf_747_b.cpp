#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	string s;
	int n;
	while(cin >> n)
	{
		cin >> s;
		map<char,int>m;
		m.clear();
		if(n % 4)
		{
			cout << "===" << endl;
		}
		else
		{
			for(int i = 0;i<n;i++)
				m[s[i]] ++;
			if(m['A'] > n/4 || m['G'] > n/4 || m['C'] > n/4 || m['T'] > n/4)
				cout << "===" << endl;
			else
			{
				int a[4];
				map<int,char>tran;
				tran[0] = 'A',tran[1] = 'G',tran[2] = 'C',tran[3] = 'T';
				a[0] = n/4 - m['A'] ,a[1] = n/4 - m['G'] ,a[2] = n/4 - m['C'],a[3] = n/4 - m['T'];
				for(int i = 0;i<n;i++)
				{
					if(s[i] == '?')
					{
						for(int i = 0;i<4;i++)
						{
							if(a[i])
							{
								a[i] --;
								char x = tran[i];
								cout << x;
								break;
							}
						}
					}
					else
						cout << s[i];
				}
				cout << endl;
			}
		}
	}
}
