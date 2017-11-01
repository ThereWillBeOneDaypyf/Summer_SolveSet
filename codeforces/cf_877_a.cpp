#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

string s;

int find(string tar)
{
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int j = 0;
		int tempi = i;
		while (tempi < s.length() && j < s.length() && s[tempi] == tar[j])
			tempi ++, j ++;
		if (j == tar.size())
			cnt ++;
	}
	return cnt;
}

int main()
{
	vector<string>v{"Danil", "Olya", "Slava", "Ann" , "Nikita"};
	while (cin >> s)
	{
		int cnt = 0;
		for (auto tar : v)
		{
			int sum = find(tar);
			//if (sum)
			cnt += sum;
		}
		if (cnt == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
