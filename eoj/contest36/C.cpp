#include<bits/stdc++.h>
using namespace std;

struct  Node
{
	char x;
	int pos, _pos;
};

int main()
{
	string s;
	while (cin >> s)
	{
		vector<Node> v;
		int cnt[26];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.length(); i++)
		{
			v.push_back({s[i], i, 0});
			cnt[s[i] - 'a'] ++;
		}
		int Max = 0;
		for (int i = 0; i < 26; i++)
			Max = max(Max, cnt[i]);
		if (Max > s.length() / 2)
		{
			cout << "impossible" << endl;
			continue;
		}
		sort(v.begin(), v.end(), [](Node a, Node b) {return a.x < b.x;});
		for (int i = 0; i < v.size(); i++)
			v[i]._pos = v[(i + Max) % s.length()].pos;
		sort(v.begin(), v.end(), [](Node a, Node b) {return a._pos < b._pos;});
		for (int i = 0; i < v.size(); i++)
			cout << v[i].x;
		cout << endl;
	}
}