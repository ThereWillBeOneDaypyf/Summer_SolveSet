#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	string s;
	while(cin >> n)
	{
		map<string,int>m;
		for(int i = 0;i<n;i++)
		{
			cin >> s;
			if(m.count(s))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			m[s] ++;
		}
	}
}
