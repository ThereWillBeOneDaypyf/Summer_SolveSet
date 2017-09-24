#include<bits/stdc++.h>
using namespace std;



int main()
{
	ios :: sync_with_stdio(false);
	map<string,int>m;
	m["rat"] = 1,m["ox"] = 2,m["tiger"] = 3,m["rabbit"] = 4;
	m["dragon"] = 5,m["snake"] = 6,m["horse"] = 7,m["sheep"] = 8;
	m["monkey"] = 9,m["rooster"] = 10,m["dog"] = 11,m["pig"] = 12;
	int T;
	cin >> T;
	while(T--)
	{
		string s1,s2;
		cin >> s1 >> s2;
		if(m[s1] >= m[s2])
			cout << - m[s1] + 12 + m[s2] << endl;
		else 
			cout << m[s2] - m[s1] << endl;
	}

}

