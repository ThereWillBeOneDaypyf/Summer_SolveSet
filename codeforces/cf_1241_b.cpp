#include <bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin >> q;
	while(q --)
	{
		string s1, s2;
		cin >> s1 >> s2;
		map<char, int> cnt;
		for(auto e : s1)
			cnt[e] ++;
		bool flag = false;
		for(auto e : s2)
			if(cnt[e])
				flag |= true;
		if(flag)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
