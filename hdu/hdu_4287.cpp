#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

string tar[N];
int main()
{
	int T;
	scanf("%d", &T);
	map<char, char>tran;
	tran['a'] = tran['b'] = tran['c'] = '2';
	tran['d'] = tran['e'] = tran['f'] = '3';
	tran['g'] = tran['h'] = tran['i'] = '4';
	tran['j'] = tran['k'] = tran['l'] = '5';
	tran['m'] = tran['n'] = tran['o'] = '6';
	tran['p'] = tran['q'] = tran['r'] = tran['s'] = '7';
	tran['t'] = tran['u'] = tran['v'] = '8';
	tran['w'] = tran['x'] = tran['y'] = tran['z'] = '9';
	while (T--)
	{
		map<string, int>cnt;
		cnt.clear();
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			cin >> tar[i];
		for (int i = 0; i < m; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < str.length(); j++)
				str[j] = tran[str[j]];
			cnt[str] ++;
		}
		for (int i = 0; i < n; i++)
		{
			if (cnt.count(tar[i]))
				cout << cnt[tar[i]] << endl;
			else
				cout << 0 << endl;
		}
	}
}