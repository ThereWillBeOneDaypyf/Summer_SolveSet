#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	map<string, int>m;
	int n;
	while (cin >> n && n)
	{
		m.clear();
		for (int i = 0 ; i < n; i++)
		{
			string s;
			cin >> s;
			m[s] ++ ;
		}
		int ans = 0;
		string ans_s;
		for (auto temp : m)
			if (temp.second > ans)
				ans = temp.second, ans_s = temp.first;
		cout << ans_s << endl;
	}
}